#ifndef DATA_FINAL_KNN_MODEL_H
#define DATA_FINAL_KNN_MODEL_H
#include "data_final_knn.h"

class Finalknn::Model : public QAbstractTableModel
{
public:
    Model(Finalknn* matrix);
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const override final;
    virtual int rowCount(const QModelIndex& parent) const override final;
    virtual int columnCount(const QModelIndex& parent) const override final;
    virtual QVariant data(const QModelIndex& index, int role) const override final;
private:
    /*!
     * Pointer to the data object for this table model.
     */
    Finalknn* _matrix;
};

#endif // DATA_FINAL_KNN_MODEL_H
