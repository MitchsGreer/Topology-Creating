#ifndef ANLYTIC_FACTORY_H
#define ANLYTIC_FACTORY_H
#include <ace/core/core.h>
//






/*!
 * Implements the Analytic factory, it will build analytics as ACE needs them for processing the data.
 */
class AnalyticFactory : public EAbstractAnalyticFactory
{
public:

    enum Type
    {
        /*!
         * Defines the import expression matrix type.
         */
        ImportExpressionMatrixType
        /*!
         * Defines the export expression matrix type.
         */
        ,ExportExpressionMatrixType
        /*!
         * Defines the distance calculation analytic
         */
        ,DistCalcType
        /*!
         * Defines the row stitcher analytic
         */
        ,KNNRowCreaterType
        /*!
         * Defines the analytic to output the anlyzed result.
         */
        ,ExportFinalknnType
        /*!
         * Defines the total number of types in this factory.
         */
        ,Total
    };

    virtual quint16 size() const override final;
    virtual QString name(quint16 type) const override final;
    virtual QString commandName(quint16 type) const override final;
    virtual std::unique_ptr<EAbstractAnalytic> make(quint16 type) const override final;

};

#endif // ANLYTIC_FACTORY_H
