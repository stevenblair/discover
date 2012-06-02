#ifndef COMMSTHREAD_H
#define COMMSTHREAD_H

#include <QThread>
#include <QTimer>

#define WPCAP
#define HAVE_REMOTE
#include <pcap.h>
#include <windows.h>
extern "C" {
#include "rapid61850/iec61850.h"
}
#include "streammanager.h"

#define BUFFER_LENGTH               1024

#define NETWORK_INTERFACE_OFF_DELAY 50  // milliseconds


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

signals:
    //void setButton(bool state);
    //void setPacketReceived(bool state);
    void addInterface(int value, QString name);
    void addSample(QString svID, QString sourceMAC, LE_IED_MUnn_PhsMeas1 dataset, quint16 smpCnt);
    void networkInterfaceStopped();
    
public slots:
    void setNetworkInterface(int value);
    void startNetworkInterface();
    void timerDone();

private:
    bool scheduledNewInterface;
    int interfaceNumber;
    bool modelReady;
    StreamManager streamManager;

    QString macFromChar(unsigned char* mac);
};

#endif // COMMSTHREAD_H
