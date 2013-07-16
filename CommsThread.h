/**
 * discover - a real-time monitoring and analysis tool for IEC 61850-9-2LE Sampled Values
 *
 * Copyright (c) 2013 Steven Blair
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

#ifndef COMMSTHREAD_H
#define COMMSTHREAD_H

#include <QThread>
#include <QTimer>

#ifdef _WIN32
    #define WPCAP
    #define HAVE_REMOTE
    #include <windows.h>
#endif
#include <pcap.h>
extern "C" {
#include "rapid61850/iec61850.h"
}
#include "StreamManager.h"

#define BUFFER_LENGTH               1024

#define NETWORK_INTERFACE_OFF_DELAY 1000  // milliseconds


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
    StreamManager *getStreamManager() {return &(this->streamManager);}

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
    QTimer *interfaceTimeout;

    bool scheduledNewInterface;
    int interfaceNumber;
    bool modelReady;
    StreamManager streamManager;

    QString macFromChar(unsigned char* mac);
};

#endif // COMMSTHREAD_H
