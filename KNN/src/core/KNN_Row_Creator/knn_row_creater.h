#ifndef KNN_ROW_CREATER_H
#define KNN_ROW_CREATER_H
#include <ace/core/core.h>
#include "../Data_Frames/data_triangle_matrix.h"
#include "../Data_Frames/data_final_knn.h"

class knnRowCreater : public EAbstractAnalytic
{
    Q_OBJECT
public:
    class Input;
    class Row; //workbklock
    class KNNresult; //result block
    class Serial;
    class CUDA;
    class OpenCL;
public:
    virtual int size() const override final;
    virtual std::unique_ptr<EAbstractAnalyticBlock> makeWork(int index) const override final;
    virtual std::unique_ptr<EAbstractAnalyticBlock> makeWork() const override final;
    virtual std::unique_ptr<EAbstractAnalyticBlock> makeResult() const override final;
    virtual void process(const EAbstractAnalyticBlock* result) override final;
    virtual EAbstractAnalyticInput* makeInput() override final;
    virtual EAbstractAnalyticSerial* makeSerial() override final;
    //virtual EAbstractAnalyticOpenCL* makeOpenCL() override final;
    virtual void initialize() override final;
    virtual void initializeOutputs() override final;
    virtual void finish() override final;
private:

    TriangleMatrix * _in {nullptr};

    Finalknn * _out{nullptr};

};

#endif // KNN_ROW_CREATER_H
