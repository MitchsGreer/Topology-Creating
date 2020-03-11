#include "knn_dist_calc_serial.h"
#include "knn_dist_calc_matrix_row.h"
#include "knn_dist_calc_sample.h"
#include "../Data_Frames/expressionmatrix_gene.h"
//





/*!
*  Implements an interface to create an serial object.
*/
KNNDistCalc::Serial::Serial(KNNDistCalc* parent) : EAbstractAnalyticSerial(parent), _base(parent)
{}





/*!
*  Implements an interface to do desired work on a work block.
*
* @param block The work block containing data to process.
*
* @result Ponter to the result of the processed block.
*/
std::unique_ptr<EAbstractAnalyticBlock> KNNDistCalc::Serial::execute(const EAbstractAnalyticBlock* block)
{
    EDEBUG_FUNC(this, &block);
    const Sample * sample {block->cast<Sample>()};
    std::unique_ptr<EAbstractAnalyticBlock> r(new MatrixRow (block->index()));
    MatrixRow * result {r->cast<MatrixRow>()};

    populateMatrixRow(sample, result->_row);

    return r;
}




/*!
*  Implements an interface to do desired work on a work block.
*
* @param sample The sample block that holds the data for the comparisons.
*
* @param row The row of the upper triangular matrix we are going to be processing.
*
* @result A count of how many samples have been compared.
*/
int KNNDistCalc::Serial::populateMatrixRow(const KNNDistCalc::Sample * sample, QVector<float>& row)
{
    EDEBUG_FUNC(this, &sample, &row);
    QVector<float> sampleRow(readRow(sample->index()));
    QVector<float> comparisonRow;
    int count = 0;


    for(int i = sample->index(); i < _base->_in->geneSize(); i++)
    {
        comparisonRow = readRow(i);
        row.append(dist(sampleRow, comparisonRow));
        ++count;
    }

    return count;
}



/*!
*  Implements an interface to find the distance between two samples.
*
* @param sample The sample that we are going to find the neighbors of.
*
* @param compare A neighbor sample we want to find the distance between.
*
* @result The distance between the two samples.
*/
float KNNDistCalc::Serial::dist(QVector<float> sample, QVector<float> compare)
{
    EDEBUG_FUNC(this, &sample, &compare);
    float sum = 0.0;
    for(int j = 0; j < compare.size(); j++)
    {
        sum += abs(compare.at(j) - sample.at(j));
    }
    return sum;
}




/*!
*  Implements an interface to do read a row from the data block sitting on the disk.
*
* @param index The index of the data row we want to grab from the data.
*
* @result A row of data from the Sampleset data.
*/
QVector<float> KNNDistCalc::Serial::readRow(int index)
{
    EDEBUG_FUNC(this, index);
    ExpressionMatrix::Gene it(_base->_in);
    QVector<float> sample;

    it.read(index);
    for(int i = 0; i < _base->_in->sampleSize(); i++)
    {
        sample.append(it.at(i));
    }



    return sample;
}
