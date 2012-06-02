#ifndef STREAMTABLEMODEL_H
#define STREAMTABLEMODEL_H

#include <QAbstractTableModel>
#include <QMap>
#include <QItemSelection>
#include <QItemSelectionModel>
#include "stream.h"

#define STREAM_TABLE_NUMBER_OF_COLUMNS                  8

#define STREAM_TABLE_COLUMNS_STATUS                     0
#define STREAM_TABLE_COLUMNS_SVID                       1
#define STREAM_TABLE_COLUMNS_SOURCE_MAC                 2
#define STREAM_TABLE_COLUMNS_SAMPLES_PER_CYCLE          3
#define STREAM_TABLE_COLUMNS_FREQ                       4
#define STREAM_TABLE_COLUMNS_VOLTAGE                    5
#define STREAM_TABLE_COLUMNS_CURRENT                    6
#define STREAM_TABLE_COLUMNS_POWER                      7

#define STREAM_TABLE_COLUMNS_STATUS_TITLE               "Status"
#define STREAM_TABLE_COLUMNS_SVID_TITLE                 "svID"
#define STREAM_TABLE_COLUMNS_SOURCE_MAC_TITLE           "Source MAC Address"
#define STREAM_TABLE_COLUMNS_SAMPLES_PER_CYCLE_TITLE    "Samples/cycle"
#define STREAM_TABLE_COLUMNS_FREQ_TITLE                 "Frequency"
#define STREAM_TABLE_COLUMNS_VOLTAGE_TITLE              "Voltage (RMS, L-L)"
#define STREAM_TABLE_COLUMNS_CURRENT_TITLE              "Current (RMS, L-L)"
#define STREAM_TABLE_COLUMNS_POWER_TITLE                "Power (3-phase)"


class StreamTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit StreamTableModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    Stream *getPhasorData(QString svID);
    void addStreamData(QString svID, QString sourceMAC, LE_IED_MUnn_PhsMeas1 *dataset, quint16 smpCnt); // TODO: make private

signals:
    void resizeColumnsToContents();
    void streamSelected(Stream* stream);
    void streamTableEmpty();                // inform comms thread to begin receiving on new network interface
    
public slots:
    void addStreamDataSlot(QString svID, QString sourceMAC, LE_IED_MUnn_PhsMeas1 dataset, quint16 smpCnt);
    void sampleRateDetermined(QString svID);
    void updateAll(bool resizeColumns);
    void getSelectedSvID(const QItemSelection &selected, const QItemSelection &prev);
    void networkInterfaceStopped();
    void setStreamTableRow(StreamTableRow *row);

private:
    QMap<QString, StreamTableRow*> rows;
    QMap<QString, Stream*> streams;
    bool blockUpdates;
    
};

#endif // STREAMTABLEMODEL_H
