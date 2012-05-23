#ifndef STREAMTABLEMODEL_H
#define STREAMTABLEMODEL_H

#include <QAbstractTableModel>
#include <QMap>
#include "stream.h"

#define STREAM_TABLE_NUMBER_OF_COLUMNS          6

#define STREAM_TABLE_COLUMNS_SVID               0
#define STREAM_TABLE_COLUMNS_FREQ               1
#define STREAM_TABLE_COLUMNS_VOLTAGE            2
#define STREAM_TABLE_COLUMNS_CURRENT            3
#define STREAM_TABLE_COLUMNS_SOURCE_MAC         4
#define STREAM_TABLE_COLUMNS_SAMPLES_PER_CYCLE  5

#define STREAM_TABLE_COLUMNS_SVID_TITLE                 "svID"
#define STREAM_TABLE_COLUMNS_FREQ_TITLE                 "Frequency"
#define STREAM_TABLE_COLUMNS_VOLTAGE_TITLE              "Voltage"
#define STREAM_TABLE_COLUMNS_CURRENT_TITLE              "Current"
#define STREAM_TABLE_COLUMNS_SOURCE_MAC_TITLE           "Source MAC"
#define STREAM_TABLE_COLUMNS_SAMPLES_PER_CYCLE_TITLE    "Samples/cycle"


class StreamTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit StreamTableModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void addStreamData(QString svID, QString sourceMAC, LE_IED_MUnn_PhsMeas1 *dataset, quint16 smpCnt); // TODO: make private
    
signals:
    void resizeColumnsToContents();
    
public slots:
    void addStreamDataSlot(QString svID, QString sourceMAC, LE_IED_MUnn_PhsMeas1 dataset, quint16 smpCnt);

private:
    QMap<QString, Stream*> streams;
    
};

#endif // STREAMTABLEMODEL_H
