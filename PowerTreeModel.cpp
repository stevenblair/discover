/**
 * discover - a real-time monitoring and analysis tool for IEC 61850-9-2LE Sampled Values
 *
 * Copyright (c) 2013 Steven Blair
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <QtGui>

#include "TreeItem.h"
#include "PowerTreeModel.h"

#define POWER_TREE_NUMBER_OF_COLUMNS                    8

#define POWER_TREE_COLUMNS_TYPE                         0
#define POWER_TREE_COLUMNS_APPARENT_POWER               1
#define POWER_TREE_COLUMNS_POWER_FACTOR                 2
#define POWER_TREE_COLUMNS_ANGLE                        3
#define POWER_TREE_COLUMNS_REAL_POWER                   4
#define POWER_TREE_COLUMNS_REACTIVE_POWER               5
#define POWER_TREE_COLUMNS_REAL_POWER_HARMONICS         6
#define POWER_TREE_COLUMNS_TRIANGLE                     7

#define POWER_TREE_COLUMNS_TYPE_TITLE                   "Type"
#define POWER_TREE_COLUMNS_APPARENT_POWER_TITLE         "Apparent power"
#define POWER_TREE_COLUMNS_POWER_FACTOR_TITLE           "p.f."
#define POWER_TREE_COLUMNS_ANGLE_TITLE                  "Angle"
#define POWER_TREE_COLUMNS_REAL_POWER_TITLE             "Real power"
#define POWER_TREE_COLUMNS_REACTIVE_POWER_TITLE         "Reactive power"
#define POWER_TREE_COLUMNS_REAL_POWER_HARMONICS_TITLE   "Real power (all harmonics)"
#define POWER_TREE_COLUMNS_TRIANGLE_TITLE               "Triangle"

PowerTreeModel::PowerTreeModel(QObject *parent) : QAbstractItemModel(parent)
{
    QList<QVariant> rootData;
    rootData << POWER_TREE_COLUMNS_TYPE_TITLE
             << POWER_TREE_COLUMNS_APPARENT_POWER_TITLE
             << POWER_TREE_COLUMNS_POWER_FACTOR_TITLE
             << POWER_TREE_COLUMNS_ANGLE_TITLE
             << POWER_TREE_COLUMNS_REAL_POWER_TITLE
             << POWER_TREE_COLUMNS_REACTIVE_POWER_TITLE
             << POWER_TREE_COLUMNS_REAL_POWER_HARMONICS_TITLE
             << POWER_TREE_COLUMNS_TRIANGLE_TITLE;
    rootItem = new TreeItem(rootData);
    //setupModelData(data.split(QString("\n")), rootItem);
}

PowerTreeModel::~PowerTreeModel()
{
    delete rootItem;
}

void PowerTreeModel::streamTableModelSelectionChanged(StreamTableModel *streamTableModel, QPersistentModelIndex *index)
{
    //qDebug() << "PowerTreeModel::streamTableModelSelectionChanged()" << this->rowCount();
    if (this->rowCount() == 0) {
        beginInsertRows(QModelIndex(), 0, 0);
        this->streamTableModel = streamTableModel;
        this->modelIndex = index;
        endInsertRows();
    }

//    QModelIndex top = createIndex(0, 0, 0);
//    QModelIndex bottom = createIndex(this->rowCount(), POWER_TREE_NUMBER_OF_COLUMNS, 0);

//    dataChanged(top, bottom);
}

int PowerTreeModel::columnCount(const QModelIndex &parent) const
{
//    if (parent.isValid())
//        return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
//    else
//        return rootItem->columnCount();
    return POWER_TREE_NUMBER_OF_COLUMNS;
}

QVariant PowerTreeModel::data(const QModelIndex &index, int role) const
{
    qDebug() << "PowerTreeModel::data()";
    if (!index.isValid()) {
        return QVariant();
    }

    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    QPointer<StreamTableRow> stream;

    if (this->streamTableModel != NULL && this->modelIndex != NULL && this->modelIndex->isValid()) {
        stream = this->streamTableModel->getRowFromIndex(this->modelIndex);
    }
    else {
        return QVariant();
    }

    if (stream.isNull()) {
        return QVariant();
    }

    if (role == Qt::DisplayRole) {
        if (index.row() == 0) {
            switch (index.column()) {
            case POWER_TREE_COLUMNS_TYPE:
                return stream->getSvID();
            case POWER_TREE_COLUMNS_APPARENT_POWER:
                return stream->getSvID();
            case POWER_TREE_COLUMNS_POWER_FACTOR:
                return stream->getSourceMAC();
            case POWER_TREE_COLUMNS_ANGLE:
                return stream->getFreq();
            case POWER_TREE_COLUMNS_REAL_POWER:
                return stream->getVoltage();
            case POWER_TREE_COLUMNS_REACTIVE_POWER:
                return stream->getCurrent();
            case POWER_TREE_COLUMNS_REAL_POWER_HARMONICS:
                return stream->getSamplesPerCycle();
            case POWER_TREE_COLUMNS_TRIANGLE:
                return stream->getPower();
            default:
                return QVariant();
            }
        }
    }


    // TODO: get data from model dynamically
    return QVariant();

//    TreeItem *item = static_cast<TreeItem*>(index.internalPointer());

//    return item->data(index.column());
}

Qt::ItemFlags PowerTreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant PowerTreeModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

QModelIndex PowerTreeModel::index(int row, int column, const QModelIndex &parent)
            const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    TreeItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    TreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex PowerTreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem *parentItem = childItem->parent();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int PowerTreeModel::rowCount(const QModelIndex &parent) const
{
//    TreeItem *parentItem;
//    if (parent.column() > 0)
//        return 0;

//    if (!parent.isValid())
//        parentItem = rootItem;
//    else
//        parentItem = static_cast<TreeItem*>(parent.internalPointer());

//    return parentItem->childCount();
    QPointer<StreamTableRow> stream;

//    if (this->streamTableModel != NULL && this->modelIndex != NULL && this->modelIndex->isValid()) {
//        stream = this->streamTableModel->getRowFromIndex(this->modelIndex);
//    }
//    else {
//        return 0;
//    }

    if (stream.isNull()) {
        return 0;
    }

    return 1;   // TODO ok to simply return 1?
}

void PowerTreeModel::setupModelData(const QStringList &lines, TreeItem *parent)
{
    QList<TreeItem*> parents;
    QList<int> indentations;
    parents << parent;
    indentations << 0;

    int number = 0;

    while (number < lines.count()) {
        int position = 0;
        while (position < lines[number].length()) {
            if (lines[number].mid(position, 1) != " ")
                break;
            position++;
        }

        QString lineData = lines[number].mid(position).trimmed();

        if (!lineData.isEmpty()) {
            // Read the column data from the rest of the line.
            QStringList columnStrings = lineData.split("\t", QString::SkipEmptyParts);
            QList<QVariant> columnData;
            for (int column = 0; column < columnStrings.count(); ++column)
                columnData << columnStrings[column];

            if (position > indentations.last()) {
                // The last child of the current parent is now the new parent
                // unless the current parent has no children.

                if (parents.last()->childCount() > 0) {
                    parents << parents.last()->child(parents.last()->childCount()-1);
                    indentations << position;
                }
            } else {
                while (position < indentations.last() && parents.count() > 0) {
                    parents.pop_back();
                    indentations.pop_back();
                }
            }

            // Append a new item to the current parent's list of children.
            parents.last()->appendChild(new TreeItem(columnData, parents.last()));
        }

        number++;
    }
}
