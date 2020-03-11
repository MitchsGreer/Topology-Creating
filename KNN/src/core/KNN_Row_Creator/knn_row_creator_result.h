#ifndef KNNRESULT_H
#define KNNRESULT_H
#include <ace/core/core.h>
#include "knn_row_creater.h"
//





class knnRowCreater::KNNresult : public EAbstractAnalyticBlock
{
   Q_OBJECT
public:
   /*!
   *  Creates an uninitialized work block
   */
   explicit KNNresult() = default;
   explicit KNNresult(int index);
   explicit KNNresult(int index, qint32 k);
   /*!
   *  Stores the results from the comparisons to the data from the work block
   */
   qint32 _k;
   QVector<float> _knnDists;
   QVector<float> _knnIndicies;
protected:
   virtual void write(QDataStream& stream) const override final;
   virtual void read(QDataStream& stream) override final;
private:
};


#endif // SAMPLE_H
