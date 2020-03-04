#include "knn_row_creator_row.h"
#include "../Data_Frames/data_triangle_matrix_iterator.h"
//






knnRowCreater::Row::Row(int index, const knnRowCreater* parent) : EAbstractAnalyticBlock(index)
{
    EDEBUG_FUNC(this, index);

    _parent = parent;
    TriangleMatrix::Iterator it(_parent->_in);
    it.read(index, _knnDists, _knnIndicies);
}






void knnRowCreater::Row::write(QDataStream& stream) const
{
    EDEBUG_FUNC(this, &stream);
    Q_UNUSED(stream);
}






void knnRowCreater::Row::read(QDataStream& stream)
{
    EDEBUG_FUNC(this, &stream);
    Q_UNUSED(stream);
}
