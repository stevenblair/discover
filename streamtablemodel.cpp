#include "streamtablemodel.h"

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
        default:
            return QVariant();
        }
    }

    return QVariant();
}

//Stream *StreamTableModel::getPhasorData(QString svID)
//{
//    Stream *stream;

//    // find stream; create new if doesn't exist
//    if (streams.contains(svID)) {
//        stream = streams.value(svID);

//        return stream;
//    }

//    return NULL;
//}

//void StreamTableModel::addStreamData(QString svID, QString sourceMAC, LE_IED_MUnn_PhsMeas1 *dataset, quint16 smpCnt)
//{
//    Stream *stream;

//    if (blockUpdates == false) {

//        // find stream; create new if doesn't exist
//        if (streams.contains(svID)) {
//            stream = streams.value(svID);

//            // check for consistent source MAC address; reject stream from "new" MAC address
//            if (QString::compare(stream->getSourceMAC(), sourceMAC) != 0) {
//                return;
//            }
//        }
//        else {
//            beginInsertRows(QModelIndex(), streams.size(), streams.size());
//            stream = new Stream(svID, sourceMAC);
//            //QObject::connect(stream, SIGNAL(sampleRateDetermined(QString)), this, SLOT(sampleRateDetermined(QString)));
//            QObject::connect(stream, SIGNAL(updateModel(bool)), this, SLOT(updateAll(bool)));
//            streams.insert(svID, stream);
//            endInsertRows();

//            emit resizeColumnsToContents();
//        }

//        stream->addSample(dataset, smpCnt);

//        // TODO: keep this here? or rely on flag in Stream for updating GUI (which will be independent of sample rate)?
//        //       or just send emit from Stream for any update type?
//    //    if (smpCnt == 3999 /*&& stream->getNumberOfSamplesCaptured() == */) {
//    //        QModelIndex top = createIndex(0, 0, 0);
//    //        QModelIndex bottom = createIndex(streams.size(), STREAM_TABLE_NUMBER_OF_COLUMNS, 0);

//    //        emit dataChanged(top, bottom);
//    //        emit resizeColumnsToContents();
//    //    }
//    }
//}

//void StreamTableModel::addStreamDataSlot(QString svID, QString sourceMAC, LE_IED_MUnn_PhsMeas1 dataset, quint16 smpCnt)
//{
//    //if (this->blockUpdates == false) {
//        addStreamData(svID, sourceMAC, &dataset, smpCnt);
//    //}
//}

//void StreamTableModel::sampleRateDetermined(QString svID)
//{
//    Stream *stream;

//    if (streams.contains(svID)) {
//        stream = streams.value(svID);

//        // only emit dataChanged() for changed row
//        int rowIndex = getIndexFromKey(svID);

//        if (rowIndex >= 0) {
//            QModelIndex top = createIndex(rowIndex, 0, 0);
//            QModelIndex bottom = createIndex(rowIndex, STREAM_TABLE_NUMBER_OF_COLUMNS - 1, 0);

//            emit dataChanged(top, bottom);
//            emit resizeColumnsToContents();
//        }
//    }
//}

//void StreamTableModel::updateAll(bool resizeColumns) {
//    QModelIndex top = createIndex(0, 0, 0);
//    QModelIndex bottom = createIndex(streams.size() - 1, STREAM_TABLE_NUMBER_OF_COLUMNS - 1, 0);

//    emit dataChanged(top, bottom);

//    if (resizeColumns) {
//        emit resizeColumnsToContents();
//    }
//}

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

//void StreamTableModel::getSelectedSvID(const QItemSelection &selected, const QItemSelection &prev)
//{
//    Q_UNUSED(prev);
//    QModelIndex index = createIndex(selected.first().top(), STREAM_TABLE_COLUMNS_SVID, 0);

//    if (!selected.isEmpty()) {
//        QMapIterator<QString, StreamTableRow*> i (rows);
//        int row = 0;
//        while (i.hasNext()) {
//            i.next();
//            if (index.row() == row) {
//                // TODO: emit something here
//                //emit streamSelected((StreamTableRow*) i.value());
//                return;
//            }
//            row++;
//        }

//        //QString svID = QString(selected.first().model()->data(index).toString());
//        //emit streamSelected(svID);
//    }
//}

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

//TODO: may need to pass a copy of StreamTableRow with the signal, rather than using pointers. Or, find source of crash.
void StreamTableModel::setStreamTableRow(StreamTableRow *row)
{
    // find stream; create new if doesn't exist
    if (rows.contains(row->getSvID())) {
        //qDebug() << "updating existing row";

        StreamTableRow *existingRow = rows.value(row->getSvID());   //TODO: need to safely delete this object
        //StreamTableRow *existingRowCopy = existingRow;

        //qDebug() << sizeof(*existingRow) << sizeof(*existingRowCopy) << sizeof(*row);

//        existingRow = row;

        rows.insert(row->getSvID(), row);

        qDebug() << existingRow << rows.value(row->getSvID());
        //qDebug() << sizeof *existingRow << sizeof *rows.value(row->getSvID());

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
        //qDebug() << "adding new row";

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
