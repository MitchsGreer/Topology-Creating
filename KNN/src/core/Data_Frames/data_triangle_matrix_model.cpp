#include "data_triangle_matrix_model.h"

TriangleMatrix::Model::Model(TriangleMatrix* matrix) : _matrix(matrix)
{
    EDEBUG_FUNC(this, &matrix);
    setParent(matrix);
}






QVariant TriangleMatrix::Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    EDEBUG_FUNC(this, section, orientation, role);
    // make sure the role is valid
    if ( role != Qt::DisplayRole )
    {
       return QVariant();
    }

    // determine whether to return a row name or column name
    switch (orientation)
    {
    case Qt::Vertical:
    {
        // get row names
        EMetaArray rowNames {_matrix->rowNames()};

        // make sure the index is valid
        if ( section >= 0 && section < rowNames.size() )
        {
           // return the specified row name
           return rowNames.at(section).toString();
        }

        // otherwise return empty string
        return QVariant();
    }
    case Qt::Horizontal:
    {
        // get column names
        EMetaArray rowNames {_matrix->rowNames()};

        // make sure the index is valid
        if ( section >= 0 && section < rowNames.size() )
        {
           // return the specified row name
           return rowNames.at(section).toString();
        }

        // otherwise return empty string
        return QVariant();
    }
    default:
       // return empty string if orientation is not valid
       return QVariant();
    }
}






int TriangleMatrix::Model::rowCount(const QModelIndex&) const
{
    EDEBUG_FUNC(this);
    return _matrix->rowSize();
}






int TriangleMatrix::Model::columnCount(const QModelIndex&) const
{
    EDEBUG_FUNC(this);
    return _matrix->rowSize();
}






QVariant TriangleMatrix::Model::data(const QModelIndex& index, int role) const
{
    EDEBUG_FUNC(this, &index, role);
    // make sure the index and role are valid
    if ( !index.isValid() || role != Qt::DisplayRole )
    {
       return QVariant();
    }

    // make sure the index is within the bounds of the dataframe
    if ( index.row() >= _matrix->_rowSize || index.column() >= _matrix->_rowSize)
    {
       return QVariant();
    }

    if(index.column() < index.row())
    {
        float value;
        qint64 pos = 0;
        qint32 columnnum = index.row() % _matrix->_rowSize - index.column();
        for(int i = 0; i < index.column(); i ++)
        {
            pos += _matrix->_rowSize - i;
        }
        _matrix->seek(sizeof(float) * (qint64)pos + 2 * sizeof(qint32) + (columnnum * sizeof(float)) + sizeof(Model *));
        _matrix->stream() >> value;

        // return the specified value
        return value;
    }
    // get the specified value from the dataframe
    float value;
    qint64 pos = 0;
    qint32 columnnum = index.column() % _matrix->_rowSize - index.row();
    for(int i = 0; i < index.row(); i ++)
    {
        pos += _matrix->_rowSize - i;
    }
    _matrix->seek(sizeof(float) * (qint64)pos + 2 * sizeof(qint32) + (columnnum * sizeof(float))+ sizeof(Model *));
    _matrix->stream() >> value;

    // return the specified value
    return value;
}
