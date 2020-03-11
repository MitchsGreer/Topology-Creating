#include "knn_dist_calc_opencl_kernel.h"
//






/*!
 * Constructs a new kernel object with the given OpenCL program and optional
 * parent.
 *
 * @param program Pointer to the OpenCL program used to build this new kernel's
 *                OpenCL resource.
 *
 * @param parent Optional parent for this new kernel object.
 */
KNNDistCalc::OpenCL::Kernel::Kernel(::OpenCL::Program* program, QObject* parent):
   ::OpenCL::Kernel(program,"dist",parent)
{
    EDEBUG_FUNC(this, &program, &parent);
}






/*!
 * Begins execution of this kernel object's OpenCL kernel using the given OpenCL
 * command queue and kernel arguments, returning the OpenCL event associated with
 * the kernel execution.
 *
 * @param queue The OpenCL command queue this kernel is executed on.
 *
 * @param buffer The OpenCL memory buffer where a row is stored and will
 *               be transformed by this kernel execution.
 *
 * @param type The mathematical operation type that will be used for the transform.
 *
 * @param amount The amount that will be used for the mathematical transform.
 *
 * @return OpenCL event associated with this kernel's execution.
 */
::OpenCL::Event KNNDistCalc::OpenCL::Kernel::execute(
        ::OpenCL::CommandQueue* queue,
        ::OpenCL::Buffer<cl_float>* expressions,
        cl_int geneSize,
        cl_int sampleSize,
        cl_int index,
        cl_int globalWorkSize,
        ::OpenCL::Buffer<cl_float>* outDists)
{
   EDEBUG_FUNC(this, &queue, &expressions, geneSize, sampleSize, index, globalWorkSize, &outDists);
   // Lock this kernel's underlying kernel class so arguments can be set.
   Locker locker {lock()};

   //setting kernel arguments
   //buffers
   setBuffer(Expressions,expressions);
   setBuffer(OutDists,outDists);

   //other arguments
   setArgument(GeneSize,geneSize);
   setArgument(SampleSize,sampleSize);
   setArgument(Index,index);
   setArgument(GlobalWorkSize,globalWorkSize);

   // Set the work sizes. The global work size is determined by the row size, but
   // it must also be a multiple of the local work size, so it is rounded up
   // accordingly.
   int localWorkSize = 1;
   int workgroupSize = (outDists->size() + localWorkSize - 1) / localWorkSize;

   setSizes(0, workgroupSize * localWorkSize, localWorkSize);

   // Execute this object's OpenCL kernel with the given command queue, returning its
   // generated OpenCL event.
   return ::OpenCL::Kernel::execute(queue);
}

