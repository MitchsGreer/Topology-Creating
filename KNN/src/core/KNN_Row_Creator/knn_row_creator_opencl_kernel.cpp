#include "knn_row_creator_opencl_kernel.h"
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
knnRowCreater::OpenCL::Kernel::Kernel(::OpenCL::Program* program, QObject* parent):
   ::OpenCL::Kernel(program,"sort",parent)
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
::OpenCL::Event knnRowCreater::OpenCL::Kernel::execute(
        ::OpenCL::CommandQueue* queue,
        ::OpenCL::Buffer<cl_float>* row,
        cl_int geneSize,
        cl_int index,
        cl_int globalWorkSize,
        ::OpenCL::Buffer<cl_float>* outDists,
        ::OpenCL::Buffer<cl_float>* outInds)
{
   EDEBUG_FUNC(this, &queue, &row, geneSize, index, globalWorkSize, &outDists, &outInds);
   // Lock this kernel's underlying kernel class so arguments can be set.
   Locker locker {lock()};

   //buffers
   setBuffer(Row,row);

   //other arguments
   setArgument(GeneSize,geneSize);
   setArgument(Index,index);
   setArgument(GlobalWorkSize,globalWorkSize);

   //output buffers
   setBuffer(OutDists,outDists);
   setBuffer(OutInds,outInds);



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

