#ifndef FINAL_KNN_ITERATOR_H
#define FINAL_KNN_ITERATOR_H
#include "data_final_knn.h"
//





/*!
*  This class implements iterator used to write to the output files
*/
class Finalknn::Iterator
{
public:
    Iterator(Finalknn* parent);
    int write(QVector<float> dists, QVector<float> indicies, int index);
    void read(QVector<float> &dists, QVector<float> &indicies, int index);

private:
    /*!
    *  Pointer to the parent data.
    */
    Finalknn * _parent;
    /*!
    *  The location of the Iterator in the file on the disk.
    */
    qint32 _index {0};
};


#endif // FINAL_KNN_ITERATOR_H
