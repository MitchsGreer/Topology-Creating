#ifndef KNN_ROW_CREATOR_OPENCL_H
#define KNN_ROW_CREATOR_OPENCL_H
#include <ace/core/core.h>
#include <ace/core/openclxx.h>
#include "knn_row_creater.h"

class knnRowCreater::OpenCL : public EAbstractAnalyticOpenCL
{
   Q_OBJECT
public:
   class Kernel;
   class Worker;
   explicit OpenCL(knnRowCreater* parent);
   virtual std::unique_ptr<EAbstractAnalyticOpenCLWorker> makeWorker() override final;
   virtual void initialize(::OpenCL::Context* context) override final;
private:
   /*!
    * Pointer to this object's parent math transform analytic.
    */
   knnRowCreater* _base;
   /*!
    * Pointer to this object's base OpenCL context used to create all other resources.
    */
   ::OpenCL::Context* _context {nullptr};
   /*!
    * Pointer to this object's OpenCL program.
    */
   ::OpenCL::Program* _program {nullptr};
   /*!
    * Pointer to this object's OpenCL command queue.
    */
   ::OpenCL::CommandQueue* _queue {nullptr};
};

#endif // KNN_ROW_CREATOR_OPENCL_H
