#include "knn_dist_calc.h"
#include "knn_dist_calc_matrix_row.h"
#include "knn_dist_calc_serial.h"
#include "knn_dist_calc_input.h"
#include "knn_dist_calc_sample.h"
#include "knn_dist_calc_opencl.h"
#include "../Data_Frames/data_triangle_matrix_iterator.h"

int KNNDistCalc::KNNDistCalc::size() const
{
    EDEBUG_FUNC(this);
    return _in->geneSize();
}






std::unique_ptr<EAbstractAnalyticBlock> KNNDistCalc::makeWork(int index) const
{
    EDEBUG_FUNC(this, index);
    return std::unique_ptr<EAbstractAnalyticBlock>(new Sample(index));
}






std::unique_ptr<EAbstractAnalyticBlock> KNNDistCalc::makeWork() const
{
    EDEBUG_FUNC(this);
    return std::unique_ptr<EAbstractAnalyticBlock>(new Sample());
}






std::unique_ptr<EAbstractAnalyticBlock> KNNDistCalc::makeResult() const
{
    EDEBUG_FUNC(this);
    return std::unique_ptr<EAbstractAnalyticBlock>(new EAbstractAnalyticBlock());
}






void KNNDistCalc::process(const EAbstractAnalyticBlock* result)
{
    EDEBUG_FUNC(this, &result);
    const MatrixRow * res {result->cast<MatrixRow>()};

    if(res->index() == 0)
    {
        _out->initialize(_in->geneNames());
        _out->setRowSize(_in->geneSize());
        _out->setk(_in->geneSize());
    }

    TriangleMatrix::Iterator it(_out);

    it.write(res->index(), res->_row);
}






EAbstractAnalyticInput* KNNDistCalc::makeInput()
{
    EDEBUG_FUNC(this);
    return new Input(this);
}






EAbstractAnalyticSerial* KNNDistCalc::makeSerial()
{
    EDEBUG_FUNC(this);
    return new Serial(this);
}






/*!
 * Make a new OpenCL object and return its pointer.
 */
EAbstractAnalyticOpenCL* KNNDistCalc::makeOpenCL()
{
   EDEBUG_FUNC(this);

   return new OpenCL(this);
}






void KNNDistCalc::initialize()
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






void KNNDistCalc::initializeOutputs()
{
    EDEBUG_FUNC(this);
    if ( !_out )
    {
       E_MAKE_EXCEPTION(e);
       e.setTitle(tr("Invalid Argument"));
       e.setDetails(tr("The required output data object was not set."));
       throw e;
    }
}






void KNNDistCalc::finish()
{
    EDEBUG_FUNC(this);
    //nothing needs to be done here, you might write meta data here
}
