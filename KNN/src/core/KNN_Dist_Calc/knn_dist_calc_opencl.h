#ifndef KNN_DIST_CALC_OPENCL_H
#define KNN_DIST_CALC_OPENCL_H
#include <ace/core/core.h>
#include <ace/core/openclxx.h>
#include <unistd.h>
#include "knn_dist_calc.h"
//

class KNNDistCalc::OpenCL : public EAbstractAnalyticOpenCL
{
   Q_OBJECT
public:
   class Kernel;
   class Worker;
   explicit OpenCL(KNNDistCalc* parent);
   virtual std::unique_ptr<EAbstractAnalyticOpenCLWorker> makeWorker() override final;
   virtual void initialize(::OpenCL::Context* context) override final;
private:
   /*!
    * Pointer to this object's parent math transform analytic.
    */
   KNNDistCalc* _base;
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
   /*!
    * Pointer to this object's OpenCL buffer for the expression matrix.
    */
   ::OpenCL::Buffer<cl_float> _expressions;
};

#endif // KNN_DIST_CALC_OPENCL_H
