#include "knn_row_creator_opencl_worker.h"
#include "knn_row_creator_opencl_worker.h"
#include "knn_row_creator_opencl_kernel.h"
#include "knn_row_creator_result.h"
#include "knn_row_creator_row.h"
#include "../Data_Frames/data_triangle_matrix_iterator.h"
//




/*!
 * Constructs a new OpenCL worker with the given math transform base, OpenCL
 * context, and OpenCL program.
 *
 * @param base Pointer to the base math transform analytic used to get argument
 *             values from.
 *
 * @param context Pointer to the OpenCL context used to create a buffer and command
 *                queue.
 *
 * @param program Pointer to OpenCL program used to create this new worker's kernel
 *                object.
 */
knnRowCreater::OpenCL::Worker::Worker(knnRowCreater* base, knnRowCreater::OpenCL* baseOpenCL, ::OpenCL::Context* context, ::OpenCL::Program* program):
   _base(base),
   _baseOpenCL(baseOpenCL),
   _queue(new ::OpenCL::CommandQueue(context,context->devices().first(),this)),
   _kernel(new OpenCL::Kernel(program,this)),
   _row(context, base->_in->rowSize()),
   _outDists(context,base->_in->rowSize()),
   _outInds(context, base->_in->rowSize())
{
    EDEBUG_FUNC(this, &base, &context, &program);
}






/*!
 * Implements the interface that reads in the given work block, executes the
 * algorithms necessary to produce its results using OpenCL acceleration, and saves
 * those results in a new results block whose pointer is returned.
 *
 * @param block Pointer to work block used to create a results block.
 *
 * @return Pointer to results block produced from the given work block.
 */
std::unique_ptr<EAbstractAnalyticBlock> knnRowCreater::OpenCL::Worker::execute(const EAbstractAnalyticBlock* block)
{
    EDEBUG_FUNC(this, &block);
    if ( ELog::isActive() )
    {
       ELog() << tr("Executing(OpenCL) work index %1.").arg(block->index());
    }
    // Cast the given generic work block to this analytic type work block _valid_.
    const Row* workBlock {block->cast<const Row>()};
    //std::unique_ptr<EAbstractAnalyticBlock> r(new KNNresult (block->index()));
    KNNresult * result = new KNNresult (block->index());

    //map the rows into the devices memory, they will be sorted on the GPU

    _row.mapWrite(_queue).wait();
    for ( int i = 0; i < _base->_in->rowSize(); i++ )
    {
        _row[i] = workBlock->_knnDists.at(i);
    }
    _row.unmap(_queue).wait();

    //execute the workers kernel
    _kernel->execute(_queue,
                     &_row,
                     _base->_in->rowSize(),
                     block->index(),
                     _base->size(),
                     &_outDists,
                     &_outInds).wait();

    // Map the row buffer to host memory for reading, read the transformed single
    // integer to _answer_, then unmap the integer buffer. Wait for all mapping to
    // finish before moving to the next step.

    _outDists.mapRead(_queue).wait();
    for ( int i = 0; i < _base->_in->rowSize(); i++ )
    {
        result->_knnDists.append(_outDists.at(i));
    }
    _outDists.unmap(_queue).wait();

    _outInds.mapRead(_queue).wait();
    for ( int i = 0; i < _base->_in->rowSize(); i++ )
    {
        result->_knnIndicies.append(_outInds.at(i));
    }
    _outInds.unmap(_queue).wait();


    return std::unique_ptr<EAbstractAnalyticBlock>(result);
}


