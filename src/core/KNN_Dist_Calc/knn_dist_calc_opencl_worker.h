#ifndef KNN_DIST_CALC_OPENCL_WORKER_H
#define KNN_DIST_CALC_OPENCL_WORKER_H
#include <ace/core/core.h>
#include "knn_dist_calc_opencl.h"

class KNNDistCalc::OpenCL::Worker : public EAbstractAnalyticOpenCLWorker
{
   Q_OBJECT
public:
   explicit Worker(KNNDistCalc* base, KNNDistCalc::OpenCL* baseOpenCL, ::OpenCL::Context* context, ::OpenCL::Program* program);
   virtual std::unique_ptr<EAbstractAnalyticBlock> execute(const EAbstractAnalyticBlock* block) override final;
private:
   /*!
    * Pointer to this worker's math transform analytic.
    */
   KNNDistCalc* _base;
   /*!
    * Pointer to the base OpenCL object.
    */
   KNNDistCalc::OpenCL* _baseOpenCL;
   /*!
    * Pointer to this worker's unique and private command queue.
    */
   ::OpenCL::CommandQueue* _queue;
   /*!
    * Pointer to this worker's unique and private kernel object.
    */
   OpenCL::Kernel* _kernel;
   /*!
    * Pointer to this worker's unique and private output buffers.
    */
   ::OpenCL::Buffer<cl_float> _outDists;
};

#endif // KNN_DIST_CALC_OPENCL_WORKER_H
