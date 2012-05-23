#ifndef STREAMTABLEMODEL_H
#define STREAMTABLEMODEL_H

#include <QAbstractTableModel>
#include <QMap>
#include "stream.h"

#define STREAM_TABLE_NUMBER_OF_COLUMNS  5

#define STREAM_TABLE_COLUMNS_SVID       0
#define STREAM_TABLE_COLUMNS_SOURCE_MAC 1
#define STREAM_TABLE_COLUMNS_FREQ       2
#define STREAM_TABLE_COLUMNS_VOLTAGE    3
#define STREAM_TABLE_COLUMNS_CURRENT    4

#define STREAM_TABLE_COLUMNS_SVID_TITLE         "svID"
#define STREAM_TABLE_COLUMNS_SOURCE_MAC_TITLE   "Source MAC"
#define STREAM_TABLE_COLUMNS_FREQ_TITLE         "Frequency"
#define STREAM_TABLE_COLUMNS_VOLTAGE_TITLE      "Voltage"
#define STREAM_TABLE_COLUMNS_CURRENT_TITLE      "Current"


class StreamTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit StreamTableModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void addStreamData(QString svID);
    
signals:
    
public slots:

private:
    QMap<QString, Stream*> streams;
    
};

#endif // STREAMTABLEMODEL_H
