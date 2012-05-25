#include "streamtablemodel.h"

#include<QDebug>

StreamTableModel::StreamTableModel(QObject *parent) : QAbstractTableModel(parent)
{
}

int StreamTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return streams.size();  // TODO: +1 for header row? Should return 0 when parent is valid?
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

    if (index.row() >= streams.size() || index.row() < 0)
    {
        return QVariant();
    }

    if (role == Qt::DisplayRole) {

        QMapIterator<QString, Stream*> i (streams);
        int row = 0;
        while (i.hasNext()) {
            i.next();
            if (index.row() == row) {
                switch (index.column()) {
                case STREAM_TABLE_COLUMNS_SVID:
                    return ((Stream*) i.value())->getSvID();
                case STREAM_TABLE_COLUMNS_SOURCE_MAC:
                    return ((Stream*) i.value())->getSourceMAC();
                case STREAM_TABLE_COLUMNS_FREQ:
                    return ((Stream*) i.value())->getFreq();
                case STREAM_TABLE_COLUMNS_VOLTAGE:
                    return ((Stream*) i.value())->getVoltage();
                case STREAM_TABLE_COLUMNS_CURRENT:
                    return ((Stream*) i.value())->getCurrent();
                case STREAM_TABLE_COLUMNS_SAMPLES_PER_CYCLE:
                    return ((Stream*) i.value())->getSamplesPerCycle();
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
        default:
            return QVariant();
        }
    }

    return QVariant();
}

void StreamTableModel::addStreamData(QString svID, QString sourceMAC, LE_IED_MUnn_PhsMeas1 *dataset, quint16 smpCnt)
{
    Stream *stream;

    // find stream; create new if doesn't exist
    if (streams.contains(svID)) {
        stream = streams.value(svID);
    }
    else {
        beginInsertRows(QModelIndex(), streams.size(), streams.size());
        stream = new Stream(svID, sourceMAC);
        //QObject::connect(stream, SIGNAL(sampleRateDetermined(QString)), this, SLOT(sampleRateDetermined(QString)));
        QObject::connect(stream, SIGNAL(updateModel(bool)), this, SLOT(updateAll(bool)));
        streams.insert(svID, stream);
        endInsertRows();
        emit resizeColumnsToContents();
    }

    stream->addSample(dataset, smpCnt);

    // TODO: keep this here? or rely on flag in Stream for updating GUI (which will be independent of sample rate)?
    //       or just send emit from Stream for any update type?
//    if (smpCnt == 3999 /*&& stream->getNumberOfSamplesCaptured() == */) {
//        QModelIndex top = createIndex(0, 0, 0);
//        QModelIndex bottom = createIndex(streams.size(), STREAM_TABLE_NUMBER_OF_COLUMNS, 0);

//        emit dataChanged(top, bottom);
//        emit resizeColumnsToContents();
//    }
}

void StreamTableModel::addStreamDataSlot(QString svID, QString sourceMAC, LE_IED_MUnn_PhsMeas1 dataset, quint16 smpCnt)
{
    addStreamData(svID, sourceMAC, &dataset, smpCnt);
}

void StreamTableModel::sampleRateDetermined(QString svID)
{
    Stream *stream;

    if (streams.contains(svID)) {
        stream = streams.value(svID);

        QModelIndex top = createIndex(0, 0, 0);
        QModelIndex bottom = createIndex(0, STREAM_TABLE_NUMBER_OF_COLUMNS - 1, 0);

        emit dataChanged(top, bottom);
        emit resizeColumnsToContents();
    }
}

void StreamTableModel::updateAll(bool resizeColumns) {
    QModelIndex top = createIndex(0, 0, 0);
    QModelIndex bottom = createIndex(streams.size(), STREAM_TABLE_NUMBER_OF_COLUMNS, 0);

    emit dataChanged(top, bottom);

    if (resizeColumns) {
        emit resizeColumnsToContents();
    }
}


void StreamTableModel::getSelectedSvID(const QItemSelection &selected, const QItemSelection &prev)
{
    QModelIndex index = createIndex(selected.first().top(), STREAM_TABLE_COLUMNS_SVID, 0);

    if (!selected.isEmpty()) {
        QString svID = QString(selected.first().model()->data(index).toString());
        emit streamSelected(svID);
    }
}
