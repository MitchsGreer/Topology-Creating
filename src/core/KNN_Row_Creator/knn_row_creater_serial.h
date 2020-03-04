#ifndef KNN_ROW_CREATER_SERIAL_H
#define KNN_ROW_CREATER_SERIAL_H
#include <ace/core/core.h>
#include "knn_row_creater.h"

class knnRowCreater::Serial : public EAbstractAnalyticSerial
{
    Q_OBJECT
public:
    explicit Serial(knnRowCreater* parent);
    virtual std::unique_ptr<EAbstractAnalyticBlock> execute(const EAbstractAnalyticBlock* block) override final;

    void sort(QVector<float> & distances, QVector<float> & indicies);
    void mergeSort(QVector<float>& left, QVector<float>& right, QVector<float>& distancess, QVector<float>& leftindicies, QVector<float>& rightindicies, QVector<float>& indicies);

private:
   /*!
   *  Pointer to the serials objects parent KNNAnalytic.
   */
    knnRowCreater* _base;
};

#endif // KNN_ROW_CREATER_SERIAL_H
