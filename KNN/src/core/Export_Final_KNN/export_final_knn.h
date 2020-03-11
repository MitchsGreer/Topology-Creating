#ifndef OUTPUT_FINAL_KNN_H
#define OUTPUT_FINAL_KNN_H
#include <ace/core/core.h>
#include "../Data_Frames/data_final_knn.h"
//






class ExportFinalknn : public EAbstractAnalytic
{
    Q_OBJECT
public:
    class Input;
public:
    virtual int size() const override final;
    virtual void process(const EAbstractAnalyticBlock* result) override final;
    virtual EAbstractAnalyticInput* makeInput() override final;
    virtual void initializeOutputs() override final;
private:
    /*!
     * Pointer files that this anlytic will output to.
     */
    QFile* _distsOut {nullptr};
    QFile* _indiciesOut {nullptr};
    /*!
     * Pointer to input data object this analytic is exporting the object to.
     */
    Finalknn* _in {nullptr};
    /*!
     * Describes how many rows there are in the data set
     */
    quint32 _rows;
    /*!
     * Describes how many columns there are in the data set
     */
    quint32 _columns;
    /*!
     * Text stream to write to the output file
     */
    QTextStream _indiciesStream;
    QTextStream _distsStream;
};

#endif // OUTPUT_FINAL_KNN_H
