//#include "knn_dist_calc_cuda_kernel.h"
////






////the program needs to be changed
//KNNDistCalc::CUDA::Kernel::Kernel(::CUDA::Program* program) : ::CUDA::Kernel(program,"mathTransform")
//{}






//::CUDA::Event KNNDistCalc::CUDA::Kernel::execute(const ::CUDA::Stream& stream, ::CUDA::Buffer<float>* buffer)
//{
//    //this is where stuff happens

//    // Set the arguments this CUDA kernel requires. This includes the global memory
//    // buffer where the row is held, the local memory buffer, the operation type,
//    // and the amount.
//    setBuffer(GlobalBuffer,buffer);
//    setArgument(GlobalSize,buffer->size());
//    //might need more arguments here, dont know yet

//    // Set the work sizes. The global work size is determined by the row size, but
//    // it must also be a multiple of the local work size, so it is rounded up
//    // accordingly.
//    int localWorkSize = 1;
//    int workgroupSize = (buffer->size() + localWorkSize - 1) / localWorkSize;

//    setSizes(workgroupSize * localWorkSize, localWorkSize);

//    // Execute this object's CUDA kernel with the given stream, returning its
//    // generated CUDA event.
//    return ::CUDA::Kernel::execute(stream);
//}
