#ifndef DATA_TRIANGLE_MATRIX_MODEL_H
#define DATA_TRIANGLE_MATRIX_MODEL_H
#include "data_triangle_matrix.h"
//







class TriangleMatrix::Model : public QAbstractTableModel
{
public:
    Model(TriangleMatrix* matrix);
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const override final;
    virtual int rowCount(const QModelIndex& parent) const override final;
    virtual int columnCount(const QModelIndex& parent) const override final;
    virtual QVariant data(const QModelIndex& index, int role) const override final;
private:
    /*!
     * Pointer to the data object for this table model.
     */
    TriangleMatrix* _matrix;
};

#endif // DATA_TRIANGLE_MATRIX_MODEL_H
