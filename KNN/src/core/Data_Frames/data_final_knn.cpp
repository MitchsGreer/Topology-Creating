#include "data_final_knn.h"
#include "data_final_knn_model.h"
//





/*!
*  Lets ACE know where the data stops in the file asosiated with this object
*
* @return A integere representation of the end of the data.
*/
qint64 Finalknn::dataEnd() const
{
    EDEBUG_FUNC(this);
    /*!
    *  gives the index of where the data ends in the stream,
    *  right now it assumes the header stores the information about the data size
    */
    return sizeof(float) * (_rowSize * _k * 2) + (sizeof(qint32) * 3) + sizeof(Model);
}





/*!
*  Called when there is a new Finallknn to be initialized, reads existing data out of the data set on disk.
*/
void Finalknn::readData()
{
    EDEBUG_FUNC(this);
    /*!
    *  Goes to the beggining of the stream.
    */
    seek(0);
    /*!
    *  Grabs the header info.
    */
    stream() >> _columnSize >> _rowSize >> _k;
}





/*!
*  Writes new data to the data set on disk.
*/
void Finalknn::writeNewData()
{
    EDEBUG_FUNC(this);
    //inits metadata object
    setMeta(EMetaObject());
    /*!
    *  Goes to the beggining of the stream.
    */
    seek(0);

    //write the header
    stream() << _columnSize << _rowSize << _k;
}





/*!
*  Returns a pointer to the qt model.
*
*  @return The pointer to a qt model object.
*/
QAbstractTableModel* Finalknn::model()
{
    EDEBUG_FUNC(this);
    if ( !_model )
    {
       _model = new Model(this);
    }
    return _model;
}





/*!
*  Executes when the analytic is done on the data.
*/
void Finalknn::finish()
{
    EDEBUG_FUNC(this);
    seek(0);

    //write the header
    stream() << _columnSize << _rowSize << _k;
}




/*!
*  Initializes the meta dta with row names.
*
* @param rowNames The row name for the data object.
*/
void Finalknn::initialize(const EMetaArray& rowNames)
{
    EDEBUG_FUNC(this,&rowNames);

    // save the row names to metadata
    EMetaObject metaObject {meta().toObject()};
    metaObject.insert("rows", rowNames);
    setMeta(metaObject);
}





/*!
*  Grabs the row names form the meta data.
*
* @return An array containing the row names.
*/
EMetaArray Finalknn::rowNames() const
{
    EDEBUG_FUNC(this);
    return meta().toObject().at("rows").toArray();
}
