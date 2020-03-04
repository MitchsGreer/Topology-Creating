#ifndef KNN_DIST_CALC_OPENCL_KERNEL_H
#define KNN_DIST_CALC_OPENCL_KERNEL_H
#include <ace/core/core.h>
#include "knn_dist_calc_opencl.h"

class KNNDistCalc::OpenCL::Kernel : public ::OpenCL::Kernel
{
   Q_OBJECT
public:
   /*!
    * Defines the arguments passed to the OpenCL kernel.
    */
   enum Argument
   {
      /*!
       * Defines the expressions buffer argument.
       */
      Expressions
      /*!
       * Defines the gene size argument.
       */
      ,GeneSize
       /*!
        * Defines the sample size argument.
        */
      ,SampleSize
       /*!
        * Defines the index argument.
        */
      ,Index
       /*!
        * Defines the work size argument.
        */
      ,GlobalWorkSize
       /*!
        * Defines the output buffer argument.
        */
      ,OutDists
   };
   explicit Kernel(::OpenCL::Program* program, QObject* parent = nullptr);
   ::OpenCL::Event execute(::OpenCL::CommandQueue* queue,
                           ::OpenCL::Buffer<cl_float>* expressions,
                           cl_int geneSize,
                           cl_int sampleSize,
                           cl_int index,
                           cl_int globalWorkSize,
                           ::OpenCL::Buffer<cl_float>* outDists);
};

#endif // KNN_DIST_CALC_OPENCL_KERNEL_H
