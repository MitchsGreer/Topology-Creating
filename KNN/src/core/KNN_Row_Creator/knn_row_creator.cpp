#include "knn_row_creater.h"
#include "knn_row_creater_input.h"
#include "knn_row_creater_serial.h"
#include "knn_row_creator_result.h"
#include "knn_row_creator_row.h"
#include "knn_row_creator_opencl.h"
#include "../Data_Frames/data_final_knn_iterator.h"

int knnRowCreater::knnRowCreater::size() const
{
    EDEBUG_FUNC(this);
    return _in->rowSize();
}







std::unique_ptr<EAbstractAnalyticBlock> knnRowCreater::makeWork(int index) const
{
    EDEBUG_FUNC(this, index);
    return std::unique_ptr<EAbstractAnalyticBlock>(new Row(index, this));
}






std::unique_ptr<EAbstractAnalyticBlock> knnRowCreater::makeWork() const
{
    EDEBUG_FUNC(this);
    return std::unique_ptr<EAbstractAnalyticBlock>(new Row());
}







std::unique_ptr<EAbstractAnalyticBlock> knnRowCreater::makeResult() const
{
    EDEBUG_FUNC(this);
    return std::unique_ptr<EAbstractAnalyticBlock>(new KNNresult());
}






void knnRowCreater::process(const EAbstractAnalyticBlock* result)
{
    EDEBUG_FUNC(this, &result);
    const KNNresult * res {result->cast<KNNresult>()};

    if(res->index() == 0)
    {
        _out->initialize(_in->rowNames());
        _out->_rowSize = _in->rowSize() * 2;
        _out->_columnSize = _in->rowSize();
        _out->_k = _in->rowSize();
    }

    Finalknn::Iterator it(_out);

    //writes the distances and then the indicies into the Finalknn
    it.write(res->_knnDists, res->_knnIndicies, res->index());
}






EAbstractAnalyticInput* knnRowCreater::makeInput()
{
    EDEBUG_FUNC(this);
    return new Input(this);
}






EAbstractAnalyticSerial* knnRowCreater::makeSerial()
{
    EDEBUG_FUNC(this);
    return new Serial(this);
}





//EAbstractAnalyticOpenCL* knnRowCreater::makeOpenCL()
//{
//    EDEBUG_FUNC(this);
//    return new OpenCL(this);
//}






void knnRowCreater::initialize()
{
    EDEBUG_FUNC(this);
    if ( !_in )
    {
       E_MAKE_EXCEPTION(e);
       e.setTitle(tr("Invalid Argument"));
       e.setDetails(tr("The required input data object was not set."));
       throw e;
    }
}






void knnRowCreater::initializeOutputs()
{
    EDEBUG_FUNC(this);
    if ( !_out )
    {
       E_MAKE_EXCEPTION(e);
       e.setTitle(tr("Invalid Argument"));
       e.setDetails(tr("The required ouyput data object was not set."));
       throw e;
    }
}






void knnRowCreater::finish()
{

}
