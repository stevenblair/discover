#include "streammanager.h"

StreamManager::StreamManager(QObject *parent) : QObject(parent)
{
}

void StreamManager::addStreamData(QString svID, QString sourceMAC, LE_IED_MUnn_PhsMeas1 *dataset, quint16 smpCnt)
{
    Stream *stream;

    //if (blockUpdates == false) {

        // find stream; create new if doesn't exist
        if (streams.contains(svID)) {
            stream = streams.value(svID);

            // check for consistent source MAC address; reject stream from "new" MAC address
            if (QString::compare(stream->getSourceMAC(), sourceMAC) != 0) {
                return;
            }
        }
        else {
            stream = new Stream(svID, sourceMAC);
            streams.insert(svID, stream);

            //TODO: this code belongs in UI thread, in StreamTableModel
            /*beginInsertRows(QModelIndex(), streams.size(), streams.size());
            //QObject::connect(stream, SIGNAL(sampleRateDetermined(QString)), this, SLOT(sampleRateDetermined(QString)));
            QObject::connect(stream, SIGNAL(updateModel(bool)), this, SLOT(updateAll(bool)));
            endInsertRows();

            emit resizeColumnsToContents();*/
        }

        stream->addSample(dataset, smpCnt);
    //}
}
