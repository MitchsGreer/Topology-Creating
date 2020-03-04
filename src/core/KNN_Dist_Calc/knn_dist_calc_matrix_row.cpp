#include "knn_dist_calc_matrix_row.h"
//





/*!
*  Implements an interface to create a work block object.
*/
KNNDistCalc::MatrixRow::MatrixRow(int index) : EAbstractAnalyticBlock(index)
{
    EDEBUG_FUNC(this);
}





/*!
*  Implements an interface to write the work block header into the file stream.
*/
void KNNDistCalc::MatrixRow::write(QDataStream& stream) const
{
    EDEBUG_FUNC(this, &stream);
    for(int i = 0; i < _row.size(); i++)
    {
        stream << _row[i];
    }
}





/*!
*  Implements an interface to read the work block header from the file stream.
*/
void KNNDistCalc::MatrixRow::read(QDataStream& stream)
{
    EDEBUG_FUNC(this, &stream);
    for(int i = 0; i < _row.size(); i++)
    {
        stream >> _row[i];
    }
}
