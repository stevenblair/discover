#ifndef POWERTREEMODEL_H
#define POWERTREEMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
#include "streamtablemodel.h"

class TreeItem;

class PowerTreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    PowerTreeModel(QObject *parent);
    ~PowerTreeModel();

    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    void streamTableModelSelectionChanged(StreamTableModel *streamTableModel, QPersistentModelIndex *index);

private:
    void setupModelData(const QStringList &lines, TreeItem *parent);

    StreamTableModel *streamTableModel;
    QPersistentModelIndex *modelIndex;

    TreeItem *rootItem;
};

#endif
