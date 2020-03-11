#ifndef EXPORT_FINAL_KNN_INPUT_H
#define EXPORT_FINAL_KNN_INPUT_H
#include <ace/core/core.h>
#include "export_final_knn.h"
//






class ExportFinalknn::Input : public EAbstractAnalyticInput
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
        *  defines the knn distances output argument
        */
       ,DistOutputData
        /*!
        *  defines knn indicies output argument
        */
       ,IndiciesOutputData
        /*!
        *  defines Total number of arguments this class contains
        */
       ,Total
    };

public:
   explicit Input(ExportFinalknn* parent);
   virtual int size() const override final;
   virtual EAbstractAnalyticInput::Type type(int index) const override final;
   virtual QVariant data(int index, Role role) const override final;
   virtual void set(int index, const QVariant& value) override final;
   virtual void set(int index, QFile* file) override final;
   virtual void set(int index, EAbstractData* data) override final;
   QVariant inputDataData(Role role) const;
   QVariant distOutputDataData(Role role) const;
   QVariant indiciesOutputDataData(Role role) const;

private:
   ExportFinalknn * _base;
};

#endif // EXPORT_FINAL_KNN_INPUT_H
