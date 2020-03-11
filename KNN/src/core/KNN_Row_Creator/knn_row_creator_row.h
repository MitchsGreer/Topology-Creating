#ifndef KNN_ROW_H
#define KNN_ROW_H
#include <ace/core/core.h>
#include "knn_row_creater.h"

class knnRowCreater::Row : public EAbstractAnalyticBlock
{
   Q_OBJECT
public:
   /*!
   *  Creates an uninitialized work block
   */
   explicit Row() = default;
   explicit Row(int index, const knnRowCreater* parent);

   QVector<float> _knnDists;
   QVector<float> _knnIndicies;

protected:
   virtual void write(QDataStream& stream) const override final;
   virtual void read(QDataStream& stream) override final;

   const knnRowCreater* _parent;
};

#endif // KNN_ROW_H
