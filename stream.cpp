#include "stream.h"
#include <QDebug>

Stream::Stream(QString svID, QString sourceMAC)
{
    this->analysed = false;
    this->svID = svID;
    this->sourceMAC = sourceMAC;
}

void Stream::addSample(LE_IED_MUnn_PhsMeas1 *dataset, quint16 smpCnt)
{
    if (smpCnt >= 0 && smpCnt < MAX_SAMPLES) {
        if (capturedSamples == 3999) {
            analysed = true;
            qDebug() << "got 3999" << smpCnt;
        }
        qDebug() << smpCnt;

        if (smpCnt == 0) {
            capturedSamples = 1;
        }
        else {
            capturedSamples++;
        }

        samples[smpCnt].voltage[0] = dataset->MUnn_TVTR_1_Vol_instMag.i;
        samples[smpCnt].voltageQuality[0] = dataset->MUnn_TVTR_1_Vol_q;
        samples[smpCnt].voltage[1] = dataset->MUnn_TVTR_2_Vol_instMag.i;
        samples[smpCnt].voltageQuality[1] = dataset->MUnn_TVTR_2_Vol_q;
        samples[smpCnt].voltage[2] = dataset->MUnn_TVTR_3_Vol_instMag.i;
        samples[smpCnt].voltageQuality[2] = dataset->MUnn_TVTR_3_Vol_q;
        samples[smpCnt].voltage[3] = dataset->MUnn_TVTR_4_Vol_instMag.i;
        samples[smpCnt].voltageQuality[3] = dataset->MUnn_TVTR_4_Vol_q;

        samples[smpCnt].current[0] = dataset->MUnn_TCTR_1_Amp_instMag.i;
        samples[smpCnt].currentQuality[0] = dataset->MUnn_TCTR_1_Amp_q;
        samples[smpCnt].current[1] = dataset->MUnn_TCTR_2_Amp_instMag.i;
        samples[smpCnt].currentQuality[1] = dataset->MUnn_TCTR_2_Amp_q;
        samples[smpCnt].current[2] = dataset->MUnn_TCTR_3_Amp_instMag.i;
        samples[smpCnt].currentQuality[2] = dataset->MUnn_TCTR_3_Amp_q;
        samples[smpCnt].current[3] = dataset->MUnn_TCTR_4_Amp_instMag.i;
        samples[smpCnt].currentQuality[3] = dataset->MUnn_TCTR_4_Amp_q;

        // TODO: do/emit something if particular count is reached?
    }
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

QString Stream::getSamplesPerCycle()
{
    if (analysed) {
        return QString("80");
    }
    else {
        return QString("--");
    }
}

bool Stream::isAnalysed()
{
    return analysed;
}
