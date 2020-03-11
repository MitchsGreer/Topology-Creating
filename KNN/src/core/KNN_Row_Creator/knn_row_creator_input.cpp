#include "knn_row_creater_input.h"
#include "../Factories/data_factory.h"
//





/*!
*  Implements an interface to create an Input data object.
*/
knnRowCreater::Input::Input(knnRowCreater* parent) : EAbstractAnalyticInput(parent), _base(parent)
{
    EDEBUG_FUNC(this, &parent);
}





/*!
*  Implements the interface that returns the number of arguments for the ImportSampleSet analytic.
*
* @return the number of arguments for the ImportSampleSet analytic.
*/
int knnRowCreater::Input::size() const
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
EAbstractAnalyticInput::Type knnRowCreater::Input::type(int index) const
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
QVariant knnRowCreater::Input::data(int index, Role role) const
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
void knnRowCreater::Input::set(int index, const QVariant& value)
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
void knnRowCreater::Input::set(int index, QFile* file)
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
void knnRowCreater::Input::set(int index, EAbstractData* data)
{
    EDEBUG_FUNC(this, index, &data);
    switch(index)
    {
    case InputData:
        _base->_in = qobject_cast<TriangleMatrix*>(data);
        break;
    case OutputData:
        _base->_out = qobject_cast<Finalknn*>(data);
        break;
    }
}





/*!
*  Implements the interface that returns role information on a specific argument.
* @param role The role you want to know about.
*
* @return A string describing the role of the argument in question.
*/
QVariant knnRowCreater::Input::inputDataData(Role role) const
{
    EDEBUG_FUNC(this, role);
    switch(role)
    {
    case CommandLineName: return QString("in");
    case Title: return tr("Input Triangular Matrix:");
    case WhatsThis: return tr("Upward trianglular matrix containing distances");
    case Role::DataType: return DataFactory::TriangleMatrixType;
    default: return QVariant();
    }
}






/*!
*  Implements the interface that returns role information on a specific argument.
* @param role The role you want to know about.
*
* @return A string describing the role of the argument in question.
*/
QVariant knnRowCreater::Input::outputDataData(Role role) const
{
    EDEBUG_FUNC(this, role);
    switch(role)
    {
    case CommandLineName: return QString("out");
    case Title: return tr("Output:");
    case WhatsThis: return tr("Final KNN values");
    case DataType: return DataFactory::FinalKNNType;
    default: return QVariant();
    }
}
