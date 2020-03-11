#ifndef KNN_ROW_CREATOR_OPENCL_KERNEL_H
#define KNN_ROW_CREATOR_OPENCL_KERNEL_H
#include "knn_row_creator_opencl.h"
//

class knnRowCreater::OpenCL::Kernel : public ::OpenCL::Kernel
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
      Row
      /*!
       * Defines the gene size argument.
       */
      ,GeneSize
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
       /*!
        * Defines the output buffer argument.
        */
      ,OutInds
   };
   explicit Kernel(::OpenCL::Program* program, QObject* parent = nullptr);
   ::OpenCL::Event execute(::OpenCL::CommandQueue* queue,
                           ::OpenCL::Buffer<cl_float>* row,
                           cl_int geneSize,
                           cl_int index,
                           cl_int globalWorkSize,
                           ::OpenCL::Buffer<cl_float>* outDists,
                           ::OpenCL::Buffer<cl_float>* outInds);
};

#endif // KNN_ROW_CREATOR_OPENCL_KERNEL_H
