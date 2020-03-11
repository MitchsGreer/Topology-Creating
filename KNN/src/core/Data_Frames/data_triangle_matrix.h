#ifndef TRIANGLE_MATRIX_H
#define TRIANGLE_MATRIX_H
#include <ace/core/core.h>

class TriangleMatrix : public EAbstractData
{
    Q_OBJECT
public:
   class Iterator;

   virtual qint64 dataEnd() const override final;
   virtual void readData() override final;
   virtual void writeNewData() override final;
   virtual QAbstractTableModel* model() override final;
   virtual void finish() override final;

   void initialize(const EMetaArray& rowNames);
   EMetaArray rowNames() const;

   qint32 rowSize() const;
   void setRowSize(qint32 newdata);

   qint32 k();
   void setk(qint32 newdata);

private:
   class Model;
private:

    qint32 _rowSize;
    qint32 _k;
    Model * _model {nullptr};
};

#endif // TRIANGLE_MATRIX_H
