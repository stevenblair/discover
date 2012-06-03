#ifndef STREAMMANAGER_H
#define STREAMMANAGER_H

#include <QObject>
#include <QMap>
#include "stream.h"
#include "streamtablemodel.h"

class StreamManager : public QObject
{
    Q_OBJECT
public:
    explicit StreamManager(QObject *parent = 0);
    void addStreamData(QString svID, QString sourceMAC, LE_IED_MUnn_PhsMeas1 *dataset, quint16 smpCnt);
    void removeAll();

    void setTableModelPtr(StreamTableModel *model) {this->model = model;}
signals:
    
public slots:

private:
    QMap<QString, Stream*> streams;
    StreamTableModel *model;
    
};

#endif // STREAMMANAGER_H
