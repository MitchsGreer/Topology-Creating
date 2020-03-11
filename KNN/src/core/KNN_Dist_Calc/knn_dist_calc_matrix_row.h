#ifndef KNN_DIST_CALC_MATRIX_ROW_H
#define KNN_DIST_CALC_MATRIX_ROW_H
#include <ace/core/core.h>
#include "knn_dist_calc.h"
//





class KNNDistCalc::MatrixRow : public EAbstractAnalyticBlock
{
   Q_OBJECT
public:
   /*!
   *  Creates an uninitialized work block
   */
   explicit MatrixRow() = default;
   explicit MatrixRow(int index);
   /*!
   *  Stores the results from the comparisons to the data from the work block
   */
   QVector<float> _row;
protected:
   virtual void write(QDataStream& stream) const override final;
   virtual void read(QDataStream& stream) override final;
private:
};

#endif // KNN_DIST_CALC_MATRIX_ROW_H
