#include "knn_row_creator_opencl.h"
#include "knn_row_creator_opencl_worker.h"
//





/*!
 * Constructs a new OpenCL object with the given math transform parent.
 *
 * @param parent Pointer to the parent math transform analytic of this new OpenCL
 *               object.
 */
knnRowCreater::OpenCL::OpenCL(knnRowCreater* parent):
   EAbstractAnalyticOpenCL(parent),
   _base(parent)
{
    EDEBUG_FUNC(this, &parent);
}






/*!
 * Implements the interface that creates and returns a new OpenCL worker for the
 * implementation's analytic type.
 *
 * @return Pointer to a new OpenCL worker object.
 */
std::unique_ptr<EAbstractAnalyticOpenCLWorker> knnRowCreater::OpenCL::OpenCL::makeWorker()
{
    EDEBUG_FUNC(this);
    return std::unique_ptr<EAbstractAnalyticOpenCLWorker>(new Worker(_base,this,_context,_program));
}






/*!
 * Implements the interface that initializes all OpenCL resources used by this
 * object's implementation.
 *
 * @param context The OpenCL context to used to initialize all other OpenCL
 *                resources.
 */
void knnRowCreater::OpenCL::initialize(::OpenCL::Context* context)
{
    EDEBUG_FUNC(this, &context);
    // Set this object's context pointer to the one given and then create this
    // object's OpenCL program.
    _context = context;
    _program = new ::OpenCL::Program(context,{"../../src/opencl/quick_sort.cl"},this);

    // create command queue
    _queue = new ::OpenCL::CommandQueue(context, context->devices().first(), this);

}

