//#include "knn_dist_calc_cuda.h"
//#include "knn_dist_calc_cuda_worker.h"
////


//KNNDistCalc::CUDA::CUDA(KNNDistCalc* parent) : EAbstractAnalyticCUDA(parent), _base(parent)
//{}






//std::unique_ptr<EAbstractAnalyticCUDAWorker> KNNDistCalc::CUDA::makeWorker()
//{
//    return std::unique_ptr<EAbstractAnalyticCUDAWorker>(new Worker(_base,this,_program));
//}






//void KNNDistCalc::CUDA::initialize(::CUDA::Context* context)
//{
//    // Set this object's context pointer to the one given and then create this
//    // object's CUDA program.
//    _context = context;
//    //the program file needs to be different
//    _program = new ::CUDA::Program({":/cuda/mathtransform.cu"},this);


//    //this is where you would set the global buffer
//}
