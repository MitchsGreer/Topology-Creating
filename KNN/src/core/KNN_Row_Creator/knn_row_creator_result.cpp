#include "knn_row_creator_result.h"
//





/*!
*  Implements the interface to create an uninitialized result block at a given index.
*
*  @param index The given index to create the block at.
*/
knnRowCreater::KNNresult::KNNresult(int index) : EAbstractAnalyticBlock(index)
{
    EDEBUG_FUNC(this, index);
}




/*!
*  Implements the interface to create an initialized result block at a given index.
*
*  @param index The given index to create the block at.
*
*  @param k The desired kth nearest neighbors to be calculated
*/
knnRowCreater::KNNresult::KNNresult(int index, qint32 k) : EAbstractAnalyticBlock(index)
{
    EDEBUG_FUNC(this, index, k);
    _k = k;
}





/*!
*  Writes this blocks data to the given data stream.
*
*  @param stream The data stream that is used to write out data.
*/
//need to change this
void knnRowCreater::KNNresult::write(QDataStream& stream) const
{
    EDEBUG_FUNC(this, &stream);
    QVector<float> v;
    v.resize(_knnDists.size());
    for(int i = 0; i < _knnDists.size(); i++)
    {
        v[i] = _knnDists[i];
    }

    stream << v;

    for(int i = 0; i < _knnDists.size(); i++)
    {
        v[i] = _knnIndicies[i];
    }

    stream << v;

    stream << _k;
}





/*!
*  Reads a blocks data from the given data stream.
*
*  @param stream The data stream that is used to write in data.
*/
void knnRowCreater::KNNresult::read(QDataStream& stream)
{
    EDEBUG_FUNC(this, &stream);
    QVector<float> v;
    v.resize(_k);
     _knnDists.resize(_k);
     _knnIndicies.resize(_k);

    stream << v;

    for(int i = 0; i < _knnDists.size(); i++)
    {
         _knnDists[i] = v[i];
    }

    stream << v;

    for(int i = 0; i < _knnDists.size(); i++)
    {
         _knnIndicies[i] = v[i];
    }

    stream << _k;
}
