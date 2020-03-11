//#ifndef KNN_DIST_CALC_CUDA_WORKER_H
//#define KNN_DIST_CALC_CUDA_WORKER_H
//#include "../KNN_Dist_Calc/knn_dist_calc_cuda.h"
//#include "../KNN_Dist_Calc/knn_dist_calc_cuda_kernel.h"
//#include <ace/core/cudaxx.h>
////

//class KNNDistCalc::CUDA::Worker : public EAbstractAnalyticCUDAWorker
//{
//   Q_OBJECT
//public:
//   explicit Worker(KNNDistCalc* base, KNNDistCalc::CUDA* baseCuda, ::CUDA::Program* program);
//   virtual std::unique_ptr<EAbstractAnalyticBlock> execute(const EAbstractAnalyticBlock* block) override final;
//private:
//   /*!
//    * Pointer to this worker's math transform analytic.
//    */
//   KNNDistCalc* _base;
//   KNNDistCalc::CUDA* _baseCuda;
//   /*!
//    * Unique stream object for this worker.
//    */
//   ::CUDA::Stream _stream;
//   /*!
//    * Unique kernel object for this worker.
//    */
//   CUDA::Kernel _kernel;
//   /*!
//    * Unique row buffer for this worker.
//    */
//   ::CUDA::Buffer<float> _buffer;
//};

//#endif // KNN_DIST_CALC_CUDA_WORKER_H
