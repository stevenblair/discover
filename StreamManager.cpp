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

#include "StreamManager.h"

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
