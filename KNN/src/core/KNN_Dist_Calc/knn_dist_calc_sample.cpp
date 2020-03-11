#include "knn_dist_calc_sample.h"
//





/*!
*  Implements the interface to create an uninitialized work block at a given index.
*
*  @param index The given index to create the block at
*/
KNNDistCalc::Sample::Sample(int index) : EAbstractAnalyticBlock(index)
{
    EDEBUG_FUNC(this, index);
}




/*!
*  Implements the interface to create an initialized work block at a given index.
*
*  @param index The location at which to create the block.
*
*  @param k The desired kth nearest neighbors to calculate
*/
KNNDistCalc::Sample::Sample(int index, qint32 k):
    EAbstractAnalyticBlock(index)
{
    EDEBUG_FUNC(this, index, k);
    _k = k;
    _row = index;
}





/*!
*  Writes this blocks data to the given data stream.
*
*  @param stream The data stream that is used to write out data.
*/
void KNNDistCalc::Sample::write(QDataStream& stream) const
{
    EDEBUG_FUNC(this, &stream);
    stream << _row << _k;
}





/*!
*  Reads a blocks data from the given data stream.
*
*  @param stream The data stream that is used to write in data.
*/
void KNNDistCalc::Sample::read(QDataStream& stream)
{
    EDEBUG_FUNC(this, &stream);
    stream >> _row >> _k;
}


