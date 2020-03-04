#ifndef KNN_ROW_CREATOR_OPENCL_WORKER_H
#define KNN_ROW_CREATOR_OPENCL_WORKER_H
#include "knn_row_creator_opencl.h"

class knnRowCreater::OpenCL::Worker : public EAbstractAnalyticOpenCLWorker
{
   Q_OBJECT
public:
   explicit Worker(knnRowCreater* base, knnRowCreater::OpenCL* baseOpenCL, ::OpenCL::Context* context, ::OpenCL::Program* program);
   virtual std::unique_ptr<EAbstractAnalyticBlock> execute(const EAbstractAnalyticBlock* block) override final;
private:
   /*!
    * Pointer to this worker's math transform analytic.
    */
   knnRowCreater* _base;
   /*!
    * Pointer to the base OpenCL object.
    */
   knnRowCreater::OpenCL* _baseOpenCL;
   /*!
    * Pointer to this worker's unique and private command queue.
    */
   ::OpenCL::CommandQueue* _queue;
   /*!
    * Pointer to this worker's unique and private kernel object.
    */
   OpenCL::Kernel* _kernel;
   /*!
    * Pointer to this worker's unique and private input row.
    */
   ::OpenCL::Buffer<cl_float> _row;
   /*!
    * Pointer to this worker's unique and private output buffers.
    */
   ::OpenCL::Buffer<cl_float> _outDists;
   ::OpenCL::Buffer<cl_float> _outInds;
};
#endif // KNN_ROW_CREATOR_OPENCL_WORKER_H
