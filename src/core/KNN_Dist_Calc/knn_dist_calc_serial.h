#ifndef KNN_DIST_CALC_SERIAL_H
#define KNN_DIST_CALC_SERIAL_H
#include <ace/core/core.h>
#include "knn_dist_calc.h"
//





/*!
*  Implements the serial worker class for its parrent KNNAnalytic.
*/
class KNNDistCalc::Serial : public EAbstractAnalyticSerial
{
   Q_OBJECT
public:
   explicit Serial(KNNDistCalc* parent);
   virtual std::unique_ptr<EAbstractAnalyticBlock> execute(const EAbstractAnalyticBlock* block) override final;

    QVector<float> readRow(int index);
    float dist(QVector<float> sample, QVector<float> compare);
    int populateMatrixRow(const KNNDistCalc::Sample * sample, QVector<float>& row);

private:
   /*!
   *  Pointer to the serials objects parent KNNAnalytic.
   */
   KNNDistCalc* _base;
};

#endif // KNN_DIST_CALC_SERIAL_H
