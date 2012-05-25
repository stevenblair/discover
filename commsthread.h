#ifndef COMMSTHREAD_H
#define COMMSTHREAD_H

#include <QThread>

#define WPCAP
#define HAVE_REMOTE
#include <pcap.h>
#include <windows.h>

extern "C" {
#include "rapid61850/iec61850.h"
}

#define BUFFER_LENGTH	1024


class CommsThread : public QThread
{
    Q_OBJECT
public:
    explicit CommsThread(QObject *parent = 0);

    pcap_t *fp;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *initWinpcap(int interfaceNumber);
    void triggerUpdateUI();

    bool initialised;
    void findNetworkInterfaces();
    void proxyPacketReceived();

protected:
    void run();

    bool scheduledNewInterface;
    int interfaceNumber;

signals:
    void updateUI();
    void setLastTATL(int value);
    void setLastStNum(int value);
    void setLastSqNum(int value);
    void setButton(bool state);
    void addInterface(int value, QString name);
    void setPacketReceived(bool state);
    void addSample(QString svID, QString sourceMAC, LE_IED_MUnn_PhsMeas1 dataset, quint16 smpCnt);
    
public slots:
    void setNetworkInterface(int value);
};

#endif // COMMSTHREAD_H
