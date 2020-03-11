#ifndef KNN_DIST_CALC_H
#define KNN_DIST_CALC_H
#include <ace/core/core.h>
#include "../Data_Frames/expressionmatrix.h"
#include "../Data_Frames/data_triangle_matrix.h"
//

class KNNDistCalc : public EAbstractAnalytic
{
    Q_OBJECT
public:
    class Input;
    class Sample; //workbklock
    class MatrixRow; //result block
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
    virtual EAbstractAnalyticOpenCL* makeOpenCL() override final;
    virtual void initialize() override final;
    virtual void initializeOutputs() override final;
    virtual void finish() override final;
private:

    ExpressionMatrix * _in {nullptr};

    TriangleMatrix * _out{nullptr};

};

#endif // KNN_DIST_CALC_H
