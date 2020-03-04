#include "knn_row_creater_serial.h"
#include "../Data_Frames/data_triangle_matrix_iterator.h"
#include "knn_row_creator_result.h"
#include "knn_row_creator_row.h"
//





knnRowCreater::Serial::Serial(knnRowCreater* parent) : EAbstractAnalyticSerial(parent), _base(parent)
{
    EDEBUG_FUNC(this, &parent);
}





std::unique_ptr<EAbstractAnalyticBlock> knnRowCreater::Serial::execute(const EAbstractAnalyticBlock* block)
{
    EDEBUG_FUNC(this, &block);
    const Row * sample {block->cast<Row>()};
    std::unique_ptr<EAbstractAnalyticBlock> r(new KNNresult (block->index()));
    KNNresult * result {r->cast<KNNresult>()};

    TriangleMatrix::Iterator it(_base->_in);

    it.read(sample->index(), result->_knnDists, result->_knnIndicies);
    sort(result->_knnDists, result->_knnIndicies);

    return r;
}






/*!
*  Implements interface to sort the distances, the lowest first, and the indicies based on what
*  distance they were attatched to. I got the underlying merge sort code from:
*
*  https://codereview.stackexchange.com/questions/167680/merge-sort-implementation-with-vectors
*
*  on june 12 2019
*
*  @param distances The vector that holds the distances of the KNN.
*
*  @param indicies The vector that stores the indicies of the KNN.
*/
void knnRowCreater::Serial::sort(QVector<float> & distances, QVector<float> & indicies)
{
    EDEBUG_FUNC(this, &distances, &indicies);
    if (distances.size() <= 1) return;

    int mid = distances.size() / 2;
    QVector<float> left;
    QVector<float> leftindicies;
    QVector<float> right;
    QVector<float> rightindicies;

    for (int j = 0; j < mid; j++)
    {
        left.push_back(distances[j]);
        leftindicies.push_back(indicies[j]);
    }
    for (int j = 0; j < (distances.size()) - mid; j++)
    {
        right.push_back(distances[mid + j]);
        rightindicies.push_back(indicies[mid + j]);
    }

    sort(left, leftindicies);
    sort(right, rightindicies);
    mergeSort(left, right, distances, leftindicies, rightindicies, indicies);
}





/*!
*  Helper function for the merge sort sort function above.
*
*  @param left The vector that holds left part of the distances of the KNN.
*
*  @param right The vector that holds right part of the distances of the KNN
*
*  @param distances The vector that holds the distances of the KNN.
*
*  @param leftindicies The vector that holds left part of the indicies of the KNN.
*
*  @param rightindicies The vector that holds right part of the indicies of the KNN
*/
void knnRowCreater::Serial::mergeSort(QVector<float>& left, QVector<float>& right, QVector<float>& distancess, QVector<float>& leftindicies, QVector<float>& rightindicies, QVector<float>& indicies)
{
    EDEBUG_FUNC(this, &left, &right, &distancess, &leftindicies, &rightindicies, &indicies);
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;

    while (j < nL && k < nR)
    {
        if (left[j] < right[k])
        {
            distancess[i] = left[j];
            indicies[i] = leftindicies[j];
            j++;
        }
        else
        {
            distancess[i] = right[k];
            indicies[i] = rightindicies[k];
            k++;
        }
        i++;
    }
    while (j < nL)
    {
        distancess[i] = left[j];
        indicies[i] = leftindicies[j];
        j++; i++;
    }
    while (k < nR)
    {
        distancess[i] = right[k];
        indicies[i] = rightindicies[k];
        k++; i++;
    }
}
