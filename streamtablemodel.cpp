/**
 * discover - a real-time monitoring and analysis tool for IEC 61850-9-2LE Sampled Values
 *
 * Copyright (c) 2012 Steven Blair
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

#include "StreamTableModel.h"

#include<QDebug>

StreamTableModel::StreamTableModel(QObject *parent) : QAbstractTableModel(parent)
{
    this->blockUpdates = false;
}

int StreamTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return rows.size();  // TODO: +1 for header row? Should return 0 when parent is valid?
}

int StreamTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return STREAM_TABLE_NUMBER_OF_COLUMNS;
}

QVariant StreamTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    if (index.row() >= rows.size() || index.row() < 0)
    {
        return QVariant();
    }

    if (role == Qt::DisplayRole) {
        QMapIterator<QString, QPointer<StreamTableRow> > i (rows);
        int row = 0;
        while (i.hasNext()) {
            i.next();
            if (index.row() == row) {
                switch (index.column()) {
                case STREAM_TABLE_COLUMNS_STATUS:
                    return ((StreamTableRow*) i.value())->isAlive();
                case STREAM_TABLE_COLUMNS_SVID:
                    return ((StreamTableRow*) i.value())->getSvID();
                case STREAM_TABLE_COLUMNS_SOURCE_MAC:
                    return ((StreamTableRow*) i.value())->getSourceMAC();
                case STREAM_TABLE_COLUMNS_FREQ:
                    return ((StreamTableRow*) i.value())->getFreq();
                case STREAM_TABLE_COLUMNS_VOLTAGE:
                    return ((StreamTableRow*) i.value())->getVoltage();
                case STREAM_TABLE_COLUMNS_CURRENT:
                    return ((StreamTableRow*) i.value())->getCurrent();
                case STREAM_TABLE_COLUMNS_SAMPLES_PER_CYCLE:
                    return ((StreamTableRow*) i.value())->getSamplesPerCycle();
                case STREAM_TABLE_COLUMNS_POWER:
                    return ((StreamTableRow*) i.value())->getPower();
                case STREAM_TABLE_COLUMNS_THD:
                    return ((StreamTableRow*) i.value())->getTHD();
                default:
                    return QVariant();
                }
            }
            row++;
        }
    }
    else if (role == Qt::ToolTipRole) {
        QMapIterator<QString, QPointer<StreamTableRow> > i (rows);
        int row = 0;
        while (i.hasNext()) {
            i.next();
            if (index.row() == row) {
                switch (index.column()) {
                case STREAM_TABLE_COLUMNS_STATUS:
                    return ((StreamTableRow*) i.value())->isAlive() ? QString(tr("Stream is being transmitted")) : QString(tr("Stream has stopped being transmitted"));
                case STREAM_TABLE_COLUMNS_VOLTAGE:
                    return ((StreamTableRow*) i.value())->getVoltage();
                case STREAM_TABLE_COLUMNS_CURRENT:
                    return ((StreamTableRow*) i.value())->getCurrent();
                case STREAM_TABLE_COLUMNS_SAMPLES_PER_CYCLE:
                    return QVariant(((StreamTableRow*) i.value())->getSamplesPerCycle() + " samples per cycle");
                default:
                    return QVariant();
                }
            }
            row++;
        }
    }

    return QVariant();
}

QVariant StreamTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case STREAM_TABLE_COLUMNS_STATUS:
            return tr(STREAM_TABLE_COLUMNS_STATUS_TITLE);
        case STREAM_TABLE_COLUMNS_SVID:
            return tr(STREAM_TABLE_COLUMNS_SVID_TITLE);
        case STREAM_TABLE_COLUMNS_SOURCE_MAC:
            return tr(STREAM_TABLE_COLUMNS_SOURCE_MAC_TITLE);
        case STREAM_TABLE_COLUMNS_FREQ:
            return tr(STREAM_TABLE_COLUMNS_FREQ_TITLE);
        case STREAM_TABLE_COLUMNS_VOLTAGE:
            return tr(STREAM_TABLE_COLUMNS_VOLTAGE_TITLE);
        case STREAM_TABLE_COLUMNS_CURRENT:
            return tr(STREAM_TABLE_COLUMNS_CURRENT_TITLE);
        case STREAM_TABLE_COLUMNS_SAMPLES_PER_CYCLE:
            return tr(STREAM_TABLE_COLUMNS_SAMPLES_PER_CYCLE_TITLE);
        case STREAM_TABLE_COLUMNS_POWER:
            return tr(STREAM_TABLE_COLUMNS_POWER_TITLE);
        case STREAM_TABLE_COLUMNS_THD:
            return tr(STREAM_TABLE_COLUMNS_THD_TITLE);
        default:
            return QVariant();
        }
    }

    return QVariant();
}

StreamTableRow *StreamTableModel::getRowFromIndex(QPersistentModelIndex *index)
{
    //qDebug() << "in getRowFromIndex()";
    if (index->isValid()) {
        QMapIterator<QString, QPointer<StreamTableRow> > i (rows);
        int rowNumber = 0;
        while (i.hasNext()) {
            //StreamTableRow *row = i.next().value();
            i.next();
            if (index->row() == rowNumber) {
                return i.value();
            }
            rowNumber++;
        }
    }

    return NULL;
}

void StreamTableModel::networkInterfaceStopped()
{
    //this->blockSignals(true);
    qDebug() << "in networkInterfaceStopped(); removing all rows";

    if (rows.size() > 0) {
        QMapIterator<QString, QPointer<StreamTableRow> > i (rows);

        //beginResetModel();
        beginRemoveRows(QModelIndex(), 0, rows.size() - 1);
        while (i.hasNext()) {
            i.next();

            QPointer<StreamTableRow> row = rows.take(((QPointer<StreamTableRow>) i.value())->getSvID());
            emit row->deleteLater();
            //((StreamTableRow*) i.value())->deleteLater();
        }
        endRemoveRows();
        //endResetModel();
    }

    emit streamTableEmpty();
}

void StreamTableModel::setStreamTableRow(StreamTableRow *row)
{
    // find stream; create new if doesn't exist
    if (rows.contains(row->getSvID())) {
        StreamTableRow *existingRow = rows.value(row->getSvID());   //TODO: need to safely delete this object
        rows.insert(row->getSvID(), row);

        // only emit dataChanged() for changed row
        int rowIndex = getIndexFromKey(row->getSvID());
        if (rowIndex >= 0) {
            QModelIndex top = createIndex(rowIndex, 0, 0);
            QModelIndex bottom = createIndex(rowIndex, STREAM_TABLE_NUMBER_OF_COLUMNS - 1, 0);

            emit dataChanged(top, bottom);
        }

        emit existingRow->deleteLater();
    }
    else {
        beginInsertRows(QModelIndex(), rows.size(), rows.size());
        rows.insert(row->getSvID(), row);
        //QObject::connect(stream, SIGNAL(sampleRateDetermined(QString)), this, SLOT(sampleRateDetermined(QString)));
        //QObject::connect(stream, SIGNAL(updateModel(bool)), this, SLOT(updateAll(bool)));
        endInsertRows();

        emit resizeColumnsToContents();
    }
}

int StreamTableModel::getIndexFromKey(QString key)
{
    QMapIterator<QString, QPointer<StreamTableRow> > i (rows);
    int rowNumber = 0;

    while (i.hasNext()) {
        i.next();
        if (i.key().compare(key) == 0) {
            return rowNumber;
        }
        rowNumber++;
    }

    return -1;
}
