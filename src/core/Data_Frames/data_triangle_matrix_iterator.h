#ifndef TRIANGLE_MATRIX_ITERATOR_H
#define TRIANGLE_MATRIX_ITERATOR_H
#include "data_triangle_matrix.h"


class TriangleMatrix::Iterator
{
public:
    Iterator(TriangleMatrix * parent);
    void read(int index, QVector<float>& dist, QVector<float>& ind);
    void write(int index, QVector<float> row);

private:
    /*!
    *  Pointer to the parent data.
    */
    TriangleMatrix * _parent;
    /*!
    *  The location of the Iterator in the file on the disk.
    */
    qint32 _index;
    /*!
    *  The sample that we are going to compare.
    */
    QVector<float> _row;
};

#endif // TRIANGLE_MATRIX_ITERATOR_H
