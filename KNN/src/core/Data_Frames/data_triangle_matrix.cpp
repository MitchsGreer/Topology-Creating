#include "data_triangle_matrix.h"
#include "data_triangle_matrix_model.h"
//






qint64 TriangleMatrix::dataEnd() const
{
    EDEBUG_FUNC(this);
    qint64 size = 0;
    for(int i = _rowSize; i >= 0; i--)
    {
        size += _rowSize - i;
    }
    size += sizeof(qint32); //for the member _rowSize
    return size * sizeof(float);
}






void TriangleMatrix::readData()
{
    EDEBUG_FUNC(this);
    seek(0);
    stream() >> _rowSize >> _k;
}






void TriangleMatrix::writeNewData()
{
    EDEBUG_FUNC(this);
    setMeta(EMetaObject());
    seek(0);
    stream() << _rowSize << _k;
}






QAbstractTableModel* TriangleMatrix::model()
{
    EDEBUG_FUNC(this);
    if ( !_model )
    {
       _model = new Model(this);
    }
    return _model;
}






void TriangleMatrix::finish()
{
    EDEBUG_FUNC(this);
    seek(0);
    stream() << _rowSize << _k;
}







qint32 TriangleMatrix::rowSize() const
{
    EDEBUG_FUNC(this);
    return _rowSize;
}




void TriangleMatrix::setRowSize(qint32 newdata)
{
    EDEBUG_FUNC(this, newdata);
    _rowSize = newdata;
}





qint32 TriangleMatrix::k()
{
    EDEBUG_FUNC(this);
    return _k;
}






void TriangleMatrix::setk(qint32 newdata)
{
    EDEBUG_FUNC(this, newdata);
    _k = newdata;
}






void TriangleMatrix::initialize(const EMetaArray& rowNames)
{
    EDEBUG_FUNC(this,&rowNames);

    // save the row names and column names to metadata
    EMetaObject metaObject {meta().toObject()};
    metaObject.insert("rows", rowNames);
    setMeta(metaObject);
}






EMetaArray TriangleMatrix::rowNames() const
{
    EDEBUG_FUNC(this);
    return meta().toObject().at("rows").toArray();
}




