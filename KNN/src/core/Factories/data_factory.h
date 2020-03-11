#ifndef DATA_FACTORY_H
#define DATA_FACTORY_H
#include <ace/core/core.h>
//






class DataFactory : public EAbstractDataFactory
{
public:
   /*!
    * Defines all available data types this program implements along with the total
    * size.
    */
   enum Type
   {
      /*!
       * Defines the dataframe data type.
       */
      ExpressionMatrixType
       /*!
        * Defines upper triangular matrix that will hold the knn distances
        */
      ,TriangleMatrixType
       /*!
        * Defines the Final Knn data type.
        */
      ,FinalKNNType
       /*!
        * Defines the total number of data types that exist.
        */
      ,Total
   };
   virtual quint16 size() const override final;
   virtual QString name(quint16 type) const override final;
   virtual QString fileExtension(quint16 type) const override final;
   virtual std::unique_ptr<EAbstractData> make(quint16 type) const override final;
};

#endif // DATA_FACTORY_H
