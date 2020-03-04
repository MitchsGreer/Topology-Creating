//#ifndef KNN_DIST_CALC_CUDA_H
//#define KNN_DIST_CALC_CUDA_H
//#include <ace/core/core.h>
//#include <ace/core/cudaxx.h>
//#include "knn_dist_calc.h"
////

//class KNNDistCalc::CUDA : public EAbstractAnalyticCUDA
//{
//   Q_OBJECT
//public:
//   //need
//   class Kernel;
//   //need
//   class Worker;
//   explicit CUDA(KNNDistCalc* parent);
//   virtual std::unique_ptr<EAbstractAnalyticCUDAWorker> makeWorker() override final;
//   //need to code program file
//   virtual void initialize(::CUDA::Context* context) override final;
//private:
//   /*!
//    * Pointer to this object's parent math transform analytic.
//    */
//   KNNDistCalc* _base;
//   /*!
//    * Pointer to this object's base CUDA context used to create all other resources.
//    */
//   ::CUDA::Context* _context {nullptr};
//   /*!
//    * Pointer to this object's CUDA program.
//    */
//   ::CUDA::Program* _program {nullptr};
//};

//#endif // KNN_DIST_CALC_CUDA_H
