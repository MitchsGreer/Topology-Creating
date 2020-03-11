#include "analytic_factory.h"
#include "../Import_Sample_Set/importexpressionmatrix.h"
#include "../Export_Sample_Set/exportexpressionmatrix.h"
#include "../Export_Final_KNN/export_final_knn.h"
#include "../KNN_Dist_Calc/knn_dist_calc.h"
#include "../KNN_Row_Creator/knn_row_creater.h"
//





/*!
 * Returns the total number of analytics that this facotry can produce.
 *
 *  @return The total number of analytics that can be implemented.
 */
quint16 AnalyticFactory::size() const
{
    EDEBUG_FUNC(this);
    return Total;
}





/*!
 * Implements the interface that tells you the name of an analytic type.
 *
 * @param type The type of analytic class in question.
 *
 *  @return The name of the analytic type as a string.
 */
QString AnalyticFactory::name(quint16 type) const
{
    EDEBUG_FUNC(this, type);
    switch(type)
    {
    case ImportExpressionMatrixType:
        return "Import Sample Set";
    case ExportExpressionMatrixType:
        return "Export Sample Set";
    case ExportFinalknnType:
        return "Export Final KNN";
    case DistCalcType:
        return "Calculate Distances";
    case KNNRowCreaterType:
        return "KNN Row Stitcher";
    default: return "";
    }
}





/*!
 * Implements the interface that givers you the command executed by an analytic of a given type.
 *
 *  @param type The type of analytic class in question.
 *
 *  @return The command the analytic type is going to per KNNAnalyticform.
 */
QString AnalyticFactory::commandName(quint16 type) const
{
    EDEBUG_FUNC(this, type);
    switch(type)
    {
    case ImportExpressionMatrixType:
        return "import";
    case ExportExpressionMatrixType:
        return "export-emx";
    case ExportFinalknnType:
        return "export-knn";
    case DistCalcType:
        return "calc";
    case KNNRowCreaterType:
        return "stitch";
    default: return "";
    }
}




/*!
 * Implements the interface that creates analytic classes based on the need by ACE.
 *
 *  @param type The type of analytic to be created.
 *
 *  @return Pointer to the newly created analytic object.
 */
std::unique_ptr<EAbstractAnalytic> AnalyticFactory::make(quint16 type) const
{
    EDEBUG_FUNC(this, type);
    switch(type)
    {
    case ImportExpressionMatrixType:
        return std::unique_ptr<EAbstractAnalytic> (new ImportExpressionMatrix);
    case ExportExpressionMatrixType:
        return std::unique_ptr<EAbstractAnalytic> (new ExportExpressionMatrix);
    case ExportFinalknnType:
        return std::unique_ptr<EAbstractAnalytic> (new ExportFinalknn);
    case DistCalcType:
        return std::unique_ptr<EAbstractAnalytic> (new KNNDistCalc);
    case KNNRowCreaterType:
        return std::unique_ptr<EAbstractAnalytic> (new knnRowCreater);
    default: return nullptr;
    }
}
