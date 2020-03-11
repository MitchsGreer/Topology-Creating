#include "data_factory.h"
#include "../Data_Frames/expressionmatrix.h"
#include "../Data_Frames/data_final_knn.h"
#include "../Data_Frames/data_triangle_matrix.h"
//





/*!
 * Returns how many different types there are.
 */
quint16 DataFactory::size() const
{
    EDEBUG_FUNC(this);
    return Total;
}





/*!
 * Returns the name of the data type.
 *
 * @param The type of data who's display name is returned.
 *
 * @return The display name of the data type passed in through type.
 */
QString DataFactory::name(quint16 type) const
{
    EDEBUG_FUNC(this, type);
    switch (type)
    {
    case ExpressionMatrixType: return "SampleSet";
        break;
    case FinalKNNType: return "Final KNN";
        break;
    case TriangleMatrixType: return "Upper triangular matrix";
    default: return QString();
    }
}





/*!
 * Returns the file extension of a given type as a string
 *
 * @param The type of data who's display name is returned.
 *
 * @return The display name of the file extension.
 */
QString DataFactory::fileExtension(quint16 type) const
{
    EDEBUG_FUNC(this, type);
    switch (type)
    {
    case ExpressionMatrixType: return "emx";
    case FinalKNNType: return "knn";
    case TriangleMatrixType: return "trm";
    default: return QString();
    }
}





/*!
 * Implements the interface that creates new abstract data objects of the given type.
 *
 * @param The type of data object that needs to be created.
 *
 * @return A unique pointer to that new abstract data object.
 */
std::unique_ptr<EAbstractData> DataFactory::make(quint16 type) const
{
    EDEBUG_FUNC(this, type);
    switch (type)
    {
    case ExpressionMatrixType: return std::unique_ptr<ExpressionMatrix>(new ExpressionMatrix());
    case FinalKNNType: return std::unique_ptr<Finalknn>(new Finalknn());
    case TriangleMatrixType: return std::unique_ptr<TriangleMatrix>(new TriangleMatrix());
    default: return nullptr;
    }
}
