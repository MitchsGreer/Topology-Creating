#ifndef KNN_DIST_CALC_INPUT_H
#define KNN_DIST_CALC_INPUT_H
#include "knn_dist_calc.h"
//

class KNNDistCalc::Input : public EAbstractAnalyticInput
{
    Q_OBJECT
public:
    enum Argument
    {
        /*!
        *  defines InputData argument
        */
       InputData
        /*!
        *  defines OutputData argument
        */
       ,OutputData
        /*!
        *  defines Total number of arguments this class contains
        */
       ,Total
    };
public:
   explicit Input(KNNDistCalc* parent);
   virtual int size() const override final;
   virtual EAbstractAnalyticInput::Type type(int index) const override final;
   virtual QVariant data(int index, Role role) const override final;
   virtual void set(int index, const QVariant& value) override final;
   virtual void set(int index, QFile* file) override final;
   virtual void set(int index, EAbstractData* data) override final;
   QVariant inputDataData(Role role) const;
   QVariant outputDataData(Role role) const;
private:
   KNNDistCalc * _base;
};

#endif // KNN_DIST_CALC_INPUT_H
