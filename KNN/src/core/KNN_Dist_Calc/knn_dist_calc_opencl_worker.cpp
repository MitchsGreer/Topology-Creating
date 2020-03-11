#include "knn_dist_calc_opencl_worker.h"
#include "knn_dist_calc_opencl_kernel.h"
#include "knn_dist_calc_sample.h"
#include "knn_dist_calc_matrix_row.h"






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
KNNDistCalc::OpenCL::Worker::Worker(KNNDistCalc* base, KNNDistCalc::OpenCL* baseOpenCL, ::OpenCL::Context* context, ::OpenCL::Program* program):
   _base(base),
   _baseOpenCL(baseOpenCL),
   _queue(new ::OpenCL::CommandQueue(context,context->devices().first(),this)),
   _kernel(new OpenCL::Kernel(program,this)),
   _outDists(context,base->_in->geneSize())
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
std::unique_ptr<EAbstractAnalyticBlock> KNNDistCalc::OpenCL::Worker::execute(const EAbstractAnalyticBlock* block)
{
    EDEBUG_FUNC(this, &block);
   if ( ELog::isActive() )
   {
      ELog() << tr("Executing(OpenCL) work index %1.").arg(block->index());
   }
   // Cast the given generic work block to this analytic type work block _valid_.
   std::unique_ptr<EAbstractAnalyticBlock> r(new MatrixRow (block->index()));
   MatrixRow * result {r->cast<MatrixRow>()};

   // Execute this object's kernel with its row buffer, this base analytic
   // object's operation type, and its amount. Wait for the kernel to finish.
   _kernel->execute(_queue,
                    &_baseOpenCL->_expressions,
                    _base->_in->geneSize(),
                    _base->_in->sampleSize(),
                    block->index(),
                    _base->size(),
                    &_outDists).wait();

   // Map the row buffer to host memory for reading, read the transformed single
   // integer to _answer_, then unmap the integer buffer. Wait for all mapping to
   // finish before moving to the next step.
   QVector<float> row(_base->_in->geneSize());

   _outDists.mapRead(_queue).wait();
   for ( int i = 0; i < row.size(); i++ )
   {
      result->_row.append(_outDists.at(i));
   }
   _outDists.unmap(_queue).wait();

   // Create a new result block with the given work block's index and
   // _row_, returning its pointer.
   return r;
}

