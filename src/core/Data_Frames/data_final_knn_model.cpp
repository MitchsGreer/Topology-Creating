#include "data_final_knn_model.h"
//





/*!
*  Constructs a new Model object.
*
* @param matrix The parent matrix of the model.
*/
Finalknn::Model::Model(Finalknn* matrix) : _matrix(matrix)
{
    EDEBUG_FUNC(this, &matrix);
    setParent(matrix);
}





/*!
*  Implements an inteface to return the header data, this makes it possible
*  for QT to create a table with clomun and row names.
*
* @param section The index of the cell in the table, either a column or row
*                depending on the orientation.
*
* @param orientation Distinquishes whether its asking for columns or rows.
*
* @param role The presentation role, we only care about the display role.
*
* @return The header information.
*/
QVariant Finalknn::Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    EDEBUG_FUNC(this, section, orientation, role);
    // make sure the role is valid
    if ( role != Qt::DisplayRole )
    {
       return QVariant();
    }
    switch (orientation)
    {
    case Qt::Vertical:
    {
       if(section % 2 == 0)
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
       }
       const QString ind = "Index Values";
       return ind;
    }
    case Qt::Horizontal:
    {
       return section;
    }
    default:
       // return empty string if orientation is not valid
       return QVariant();
    }
}





/*!
*  Implements an interface to get the row count for the matrix.
*
* @return An integer representation of the row size.
*/
int Finalknn::Model::rowCount(const QModelIndex&) const
{
    EDEBUG_FUNC(this);
    return _matrix->_rowSize;
}





/*!
*  Implements an interface to get the column count for the matrix.
*
* @return An integer representation of the column size.
*/
int Finalknn::Model::columnCount(const QModelIndex&) const
{
    EDEBUG_FUNC(this);
    return _matrix->_columnSize;
}





/*!
*  Implements an interface retrive the data from the data object so it can be
*  displayed by QT.
*
* @param index The index on the of the cell its trying to fill on the table.
*
* @param role The presentation role, we only care about the display role.
*
* @return The data from the data object.
*/
QVariant Finalknn::Model::data(const QModelIndex& index, int role) const
{
    EDEBUG_FUNC(this, &index, role);
    // make sure the index and role are valid
    if ( !index.isValid() || role != Qt::DisplayRole )
    {
       return QVariant();
    }

    // make sure the index is within the bounds of the dataframe
    if ( index.row() >= _matrix->_rowSize || index.column() >= _matrix->_columnSize )
    {
       return QVariant();
    }

    // get the specified value from the dataframe
    float value;
    qint64 headersize = 3 * sizeof(qint32) + sizeof(Model*);
    _matrix->seek(headersize + (index.row() * _matrix->_columnSize + index.column()) * sizeof(float));
    _matrix->stream() >> value;

    // return the specified value
    return value;
}
