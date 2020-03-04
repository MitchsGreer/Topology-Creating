#ifndef SAMPLE_H
#define SAMPLE_H
#include <ace/core/core.h>
#include "knn_dist_calc.h"
//




class KNNDistCalc::Sample : public EAbstractAnalyticBlock
{
   Q_OBJECT
public:
   /*!
   *  Creates an uninitialized work block
   */
   explicit Sample() = default;
   explicit Sample(int index);
   explicit Sample(int index, qint32 k);
   /*!
   *  The data stored in each work block. The given column will compare to the data
   *  in the file and get the kth nearest neighbors
   */
   qint32 _k {0};
   qint32 _row {0};
protected:
   virtual void write(QDataStream& stream) const override final;
   virtual void read(QDataStream& stream) override final;
};

#endif // SAMPLE_H
