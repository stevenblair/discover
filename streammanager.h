#ifndef STREAMMANAGER_H
#define STREAMMANAGER_H

#include <QObject>
#include <QMap>
#include "stream.h"

class StreamManager : public QObject
{
    Q_OBJECT
public:
    explicit StreamManager(QObject *parent = 0);
    void addStreamData(QString svID, QString sourceMAC, LE_IED_MUnn_PhsMeas1 *dataset, quint16 smpCnt);
    
signals:
    
public slots:

private:
    QMap<QString, Stream*> streams;
    
};

#endif // STREAMMANAGER_H
