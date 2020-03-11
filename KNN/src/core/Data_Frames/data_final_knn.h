#ifndef FINALKNN_H
#define FINALKNN_H
#include <ace/core/core.h>
//






/*!
* This class implements the Final KNN information, it stores all of the data that refers to the KNN of all the
* samples reletive to each other.
*/
class Finalknn : public EAbstractData
{
    Q_OBJECT
public:
    class Iterator;
public:
   virtual qint64 dataEnd() const override final;
   virtual void readData() override final;
   virtual void writeNewData() override final;
   virtual QAbstractTableModel* model() override final;
   virtual void finish() override final;

    void initialize(const EMetaArray& rowNames);
    EMetaArray rowNames() const;

   /*!
   *  The number of desired kth nearest neighbors.
   */
    qint32 _k;
   /*!
   *  The column size of the data being stored by this data object.
   */
    qint32 _columnSize;
   /*!
   *  The row size of the data being stored by this data object.
   */
    qint32 _rowSize;
private:
    class Model;
private:
    /*!
     * Pointer to a qt table model for this class.
     */
    Model* _model {nullptr};
};

#endif // FINALKNN_H
