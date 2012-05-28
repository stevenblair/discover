#include "commsthread.h"

CommsThread *commsThreadPtr;

unsigned char buf[BUFFER_LENGTH] = {0};

void sendPacket(pcap_t *fp, const u_char *buf, int length) {
    if (pcap_sendpacket(fp, buf, length) != 0) {
        fprintf(stderr,"\nError sending the packet: %s\n", pcap_geterr(fp));
    }
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    gse_sv_packet_filter((unsigned char *) pkt_data, header->len);
}

void SVRecv(CTYPE_INT16U smpCnt) {
    commsThreadPtr->proxyPacketReceived();
}

CommsThread::CommsThread(QObject *parent) : QThread(parent)
{
    commsThreadPtr = this;
    interfaceNumber = 0;
    scheduledNewInterface = false;
    modelReady = false;
}

void CommsThread::proxyPacketReceived() {
    if (scheduledNewInterface == false) {
        emit addSample(QString((const char*) LE_IED_RECV.S1.MUnn.IEC_61850_9_2LETCTR_1.sv_inputs_MSVCB01.svID), QString("Source MAC placeholder"), LE_IED_RECV.S1.MUnn.IEC_61850_9_2LETCTR_1.sv_inputs_MSVCB01.LE_IED_MUnn_PhsMeas1, LE_IED_RECV.S1.MUnn.IEC_61850_9_2LETCTR_1.sv_inputs_MSVCB01.smpCnt);
    }
}

void CommsThread::setNetworkInterface(int value) {
    if (value != interfaceNumber) {
        scheduledNewInterface = true;
        if (fp != NULL) {
            pcap_breakloop(fp);
            pcap_close(fp);
        }
        interfaceNumber = value;
        emit networkInterfaceStopped();
    }
}

void CommsThread::startNetworkInterface()
{
    modelReady = true;  // TODO: still not a clean transition; maybe start one-shot, then call emit networkInterfaceStopped()?
}


void CommsThread::findNetworkInterfaces() {
    pcap_if_t *list_if;
    int interfaceCount = 0;

    /* Retrieve the device list from the local machine */
    if (pcap_findalldevs_ex((char *) PCAP_SRC_IF_STRING, NULL /* auth is not needed */, &list_if, CommsThread::errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs_ex: %s\n", CommsThread::errbuf);
        exit(1);
    }

    while (list_if != NULL) {
        emit addInterface(interfaceCount, QString(list_if->description));
        list_if = list_if->next;
        interfaceCount++;
    }
}

pcap_t *CommsThread::initWinpcap(int interfaceNumber) {
    pcap_t *fpl;
    pcap_if_t *alldevs;
    pcap_if_t *used_if;
    pcap_if_t *list_if;
    int interfaceCount = 0;

    /* Retrieve the device list from the local machine */
    if (pcap_findalldevs_ex((char *) PCAP_SRC_IF_STRING, NULL /* auth is not needed */, &alldevs, CommsThread::errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs_ex: %s\n", CommsThread::errbuf);
        exit(1);
    }

    // list all interfaces
    list_if = alldevs;
    used_if = list_if;  // default to first interface

    while (list_if != NULL) {
        if (interfaceCount == interfaceNumber) {
            used_if = list_if;
            break;
        }

        list_if = list_if->next;
        interfaceCount++;
    }

    //fprintf(stdout, "%s\n", /*interfaceName.toLocal8Bit().data()*/used_if->description);
    //fflush(stdout);

    if ((fpl = pcap_open_live(used_if->name,    // name of the device
                             65536,             // portion of the packet to capture. It doesn't matter in this case
                             1,                 // promiscuous mode (nonzero means promiscuous)
                             1,                 // read timeout
                             errbuf             // error buffer
                             )) == NULL)
    {
        fprintf(stderr, "\nUnable to open the adapter. %s is not supported by WinPcap\n", alldevs->name);
        exit(2);
    }

    pcap_freealldevs(alldevs);

    return fpl;
}

void CommsThread::run()
{
    initialise_iec61850();
    LE_IED_RECV.S1.MUnn.IEC_61850_9_2LETCTR_1.sv_inputs_MSVCB01.datasetDecodeDone = &SVRecv;

    findNetworkInterfaces();

    fp = initWinpcap(interfaceNumber);
    //pcap_setmintocopy(fp, 1);

    forever {
        //msleep(1);

        if (fp != NULL && scheduledNewInterface == false) {
            pcap_loop(fp, 1, packet_handler, NULL);
        }

        if (scheduledNewInterface == true && modelReady == true) {
            scheduledNewInterface = false;
            modelReady = false;

            //pcap_close(fp);
            fp = initWinpcap(interfaceNumber);
        }
    }
}
