#include "knn_dist_calc_input.h"
#include "../Factories/data_factory.h"
#include "../Data_Frames/expressionmatrix.h"
#include "../Data_Frames/data_triangle_matrix.h"
//




/*!
*  Implements an interface to create an Input data object.
*/
KNNDistCalc::Input::Input(KNNDistCalc* parent) : EAbstractAnalyticInput(parent), _base(parent)
{
    EDEBUG_FUNC(this, &parent);
}





/*!
*  Implements the interface that returns the number of arguments for the ImportSampleSet analytic.
*
* @return the number of arguments for the ImportSampleSet analytic.
*/
int KNNDistCalc::Input::size() const
{
    EDEBUG_FUNC(this);
    return Total;
}





/*!
*  Implements the interface that returns the type of a particular argument.
*
* @param index The argument in quastion.
*
* @return the The type of an argument.
*/
EAbstractAnalyticInput::Type KNNDistCalc::Input::type(int index) const
{
    EDEBUG_FUNC(this, index);
    switch(index)
    {
    case InputData: return Type::DataIn;
    case OutputData: return Type::DataOut;
    default: return Type::Boolean;
    }
}





/*!
*  Implements the interface that returns information about an argument.
*
* @param index The argument in quastion.
*
* @param role The role you want to know about.
*
* @return A string describing the role of the argument in question.
*/
QVariant KNNDistCalc::Input::data(int index, Role role) const
{
    EDEBUG_FUNC(this, index, role);
    switch(index)
    {
    case InputData: return inputDataData(role);
    case OutputData: return outputDataData(role);
    default: return QVariant();
    }
}





/*!
*  Implements the interface that returns role information on a specific argument.
* @param role The role you want to know about.
*
* @return A string describing the role of the argument in question.
*/
QVariant KNNDistCalc::Input::inputDataData(Role role) const
{
    EDEBUG_FUNC(this, role);
    switch(role)
    {
    case CommandLineName: return QString("in");
    case Title: return tr("Input Expresion Matrix:");
    case WhatsThis: return tr("Expresion Matrix");
    case Role::DataType: return DataFactory::ExpressionMatrixType;
    default: return QVariant();
    }
}





/*!
*  Implements the interface that returns role information on a specific argument.
* @param role The role you want to know about.
*
* @return A string describing the role of the argument in question.
*/
QVariant KNNDistCalc::Input::outputDataData(Role role) const
{
    EDEBUG_FUNC(this, role);
    switch(role)
    {
    case CommandLineName: return QString("out");
    case Title: return tr("Output:");
    case WhatsThis: return tr("An upward triangular matrix holding distance values");
    case DataType: return DataFactory::TriangleMatrixType;
    default: return QVariant();
    }
}





/*!
*  Implements the interface that sets a value for a particualr argument.
*
* @param index The argument that needs to be set.
*
* @param value The value you are changing the arguement too.
*/
void KNNDistCalc::Input::set(int index, const QVariant& value)
{
    EDEBUG_FUNC(this, index, &value);
    Q_UNUSED(index);
    Q_UNUSED(value);
}





/*!
*  Implements the interface that sets a file for a given argument.
*
* @param index The argument that needs to be set
*
* @param file The file the argument is going to be changed to.
*/
void KNNDistCalc::Input::set(int index, QFile* file)
{
    EDEBUG_FUNC(this, index, &file);
    Q_UNUSED(index);
    Q_UNUSED(file);
}





/*!
*  Implements the interface that sets a data object for a given argument.
*
* @param index The argument that needs to be set
*
* @param data The data object that the argument is going to be changed to.
*/
void KNNDistCalc::Input::set(int index, EAbstractData* data)
{
    EDEBUG_FUNC(this, index, &data);
    switch(index)
    {
    case InputData:
        _base->_in = qobject_cast<ExpressionMatrix*>(data);
        break;
    case OutputData:
        _base->_out = qobject_cast<TriangleMatrix*>(data);
        break;
    }
}
