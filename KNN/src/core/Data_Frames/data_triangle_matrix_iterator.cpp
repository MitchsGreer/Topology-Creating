#include "data_triangle_matrix_iterator.h"
//





/*!
*  Creates a new Iterator object with the parent set to the given parent
*
*  @param the parent data class to iterate through
*/
TriangleMatrix::Iterator::Iterator(TriangleMatrix * parent)
{
    EDEBUG_FUNC(this, &parent);
    _parent = parent;
    _index = 0;
    _row.resize(_parent->_rowSize);
}





/*!
*  Creates a new Iterator object with the parent set to the given parent
*
*  @param index Reads the next row starting at the index
*
*  @return The vector it has just read.
*/
void TriangleMatrix::Iterator::read(int index, QVector<float>& dist, QVector<float>& ind)
{
    EDEBUG_FUNC(this, index, &dist, &ind);
    if(index < 0 || index > _parent->rowSize())
    {
        E_MAKE_EXCEPTION(e)
        e.setTitle(tr("Seek Error"));
        e.setDetails(tr("TriangleMatrix Iterator encountered an unknown error."));
        throw e;
    }

    //go back to the beggining
    _parent->seek(0);

    float k = 0.0;
    qint64 pos = 2 * sizeof(qint32) + (sizeof(float) * index + sizeof(Model *)); //starts as the header

    //for all of the things not in the same row
    for(int i = 0; i < index; i++)
    {
        _parent->seek(pos);
        ind.append(i);
        _parent->stream() >> k;
        dist.append(k);
        pos += (_parent->rowSize() - (i + 1)) * sizeof(float);
    }
    _parent->seek(pos);
    //for all of the things in the same row as the index
    for(int i = 0; i < _parent->rowSize() - index; i++)
    {
        _parent->stream() >> k;
        ind.append(i + index);
        dist.append(k);
    }
}






void TriangleMatrix::Iterator::write(int index, QVector<float> row)
{
    EDEBUG_FUNC(this, index, &row);
    if(index < 0 || index > (_parent->rowSize()))
    {
        E_MAKE_EXCEPTION(e)
        e.setTitle(tr("Seek Error"));
        e.setDetails(tr("TriangleMatrix Iterator encountered an unknown error."));
        throw e;
    }

    //getting us to the right location
    qint64 pos = 0;
    for(int i = 0; i < index; i ++)
    {
        pos += _parent->_rowSize - i;
    }
    _parent->seek(sizeof(float) * (qint64)pos + 2 * sizeof(qint32) + sizeof(Model *));

    for (int i = 0; i < _parent->_rowSize - index; i++)
    {
        _parent->stream() << row[i];
    }

}
