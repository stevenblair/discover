#include "streammanager.h"

StreamManager::StreamManager(QObject *parent) : QObject(parent)
{
}

void StreamManager::addStreamData(QString svID, QString sourceMAC, LE_IED_MUnn_PhsMeas1 *dataset, quint16 smpCnt)
{
    Stream *stream;

    // find stream; create new if doesn't exist
    if (streams.contains(svID)) {
        stream = streams.value(svID);

        // check for consistent source MAC address; reject SV stream from "new" MAC address
        if (QString::compare(stream->getSourceMAC(), sourceMAC) != 0) {
            return;
        }
    }
    else {
        stream = new Stream(svID, sourceMAC);
        connect(stream, SIGNAL(setStreamTableRow(StreamTableRow*)), model, SLOT(setStreamTableRow(StreamTableRow*)));
        streams.insert(svID, stream);
    }

    stream->addSample(dataset, smpCnt);
}

void StreamManager::removeAll() {
    QMapIterator<QString, Stream*> i (streams);

    while (i.hasNext()) {
        i.next();

        Stream *stream = ((Stream*) i.value());

        streams.remove(stream->getSvID());
        stream->disable();  //TODO: should delete?
        //((Stream*) i.value())->deleteLater();
        //delete stream;
    }
}
