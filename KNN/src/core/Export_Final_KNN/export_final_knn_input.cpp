#include "export_final_knn_input.h"
#include "../Factories/data_factory.h"
#include "../Data_Frames/data_final_knn.h"
//





/*!
*  Implements an interface to create an Input data object.
*/
ExportFinalknn::Input::Input(ExportFinalknn* parent) : EAbstractAnalyticInput(parent), _base(parent)
{
    EDEBUG_FUNC(this, &parent);
}





/*!
*  Implements the interface that returns the number of arguments for the ExportFinalknn analytic.
*
* @return the number of arguments for the ExportFinalknn analytic.
*/
int ExportFinalknn::Input::size() const
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
EAbstractAnalyticInput::Type ExportFinalknn::Input::type(int index) const
{
    EDEBUG_FUNC(this, index);
    switch(index)
    {
    case InputData: return Type::DataIn;
    case DistOutputData: return Type::FileOut;
    case IndiciesOutputData: return Type::FileOut;
    default : return Type::Boolean;
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
QVariant ExportFinalknn::Input::data(int index, Role role) const
{
    EDEBUG_FUNC(this, index, role);
    switch(index)
    {
    case InputData: return inputDataData(role);
    case DistOutputData: return distOutputDataData(role);
    case IndiciesOutputData: return indiciesOutputDataData(role);
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
void ExportFinalknn::Input::set(int index, const QVariant& value)
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
void ExportFinalknn::Input::set(int index, QFile* file)
{
    EDEBUG_FUNC(this, index, &file);
    switch(index)
    {
    case DistOutputData:
        _base->_distsOut = file;
        break;
    case IndiciesOutputData:
        _base->_indiciesOut = file;
        break;
    }
}





/*!
*  Implements the interface that sets a data object for a given argument.
*
* @param index The argument that needs to be set
*
* @param data The data object that the argument is going to be changed to.
*/
void ExportFinalknn::Input::set(int index, EAbstractData* data)
{
    EDEBUG_FUNC(this, index, &data);
    switch(index)
    {
    case InputData:
        _base->_in = qobject_cast<Finalknn*>(data);
    }
}





/*!
*  Implements the interface that returns role information on a specific argument.
* @param role The role you want to know about.
*
* @return A string describing the role of the argument in question.
*/
QVariant ExportFinalknn::Input::inputDataData(Role role) const
{
    EDEBUG_FUNC(this, role);
    switch(role)
    {
    case CommandLineName: return QString("in");
    case Title: return tr("Input:");
    case WhatsThis: return tr("Input data object of type Finalknn");
    case DataType: return DataFactory::FinalKNNType;
    default: return QVariant();
    }
}





/*!
*  Implements the interface that returns role information on a specific argument.
* @param role The role you want to know about.
*
* @return A string describing the role of the argument in question.
*/
QVariant ExportFinalknn::Input::distOutputDataData(Role role) const
{
    EDEBUG_FUNC(this, role);
    switch(role)
    {
    case CommandLineName: return QString("distout");
    case Title: return tr("Distance Output Text File:");
    case WhatsThis: return tr("Raw text file containing knn distances to export");
    case FileFilters: return tr("Raw text file containing distances (*.txt)");
    default: return QVariant();
    }
}





/*!
*  Implements the interface that returns role information on a specific argument.
* @param role The role you want to know about.
*
* @return A string describing the role of the argument in question.
*/
QVariant ExportFinalknn::Input::indiciesOutputDataData(Role role) const
{
    EDEBUG_FUNC(this, role);
    switch(role)
    {
    case CommandLineName: return QString("indiciesout");
    case Title: return tr("Indicies Output Text File:");
    case WhatsThis: return tr("Raw text file containing knn Indicies to export");
    case FileFilters: return tr("Raw text file containing Indicies (*.txt)");
    default: return QVariant();
    }
}
