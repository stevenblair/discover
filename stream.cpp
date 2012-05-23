#include "stream.h"

Stream::Stream(QString svID)
{
    this->analysed = false;
    this->svID = svID;
    this->sourceMAC = QString("MAC");
}

void Stream::addSample(LE_IED_MUnn_PhsMeas1 *dataset, quint16 smpCnt)
{
}

QString Stream::getSvID()
{
    return this->svID;
}

QString Stream::getSourceMAC()
{
    return this->sourceMAC;
}

QString Stream::getFreq()
{
    if (analysed) {
        return QString("50.1 Hz");
    }
    else {
        return QString("--");
    }
}

QString Stream::getVoltage()
{
    if (analysed) {
        return QString("11.0 kV");
    }
    else {
        return QString("--");
    }
}

QString Stream::getCurrent()
{
    if (analysed) {
        return QString("1.05 kA");
    }
    else {
        return QString("--");
    }
}
