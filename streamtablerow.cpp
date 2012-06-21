#include "streamtablerow.h"

StreamTableRow::StreamTableRow(QObject *parent) : QObject(parent)
{

}
StreamTableRow::StreamTableRow(Stream *stream, QObject *parent) : QObject(parent)
{
    setup(stream);
}

void StreamTableRow::setup(Stream *stream)
{
    //this->stream = stream;
    this->status = stream->isAlive();
    this->svID = QString(stream->getSvID());
    this->sourceMAC = QString(stream->getSourceMAC());

    if (stream->getSampleRate()->isKnown()) {
        this->sampleRate = SampleRate(stream->getSampleRate()->getNominalFrequency(), stream->getSampleRate()->getSamplesPerCycle());
    }
    else {
        this->sampleRate = SampleRate();
    }

    this->analysed = stream->isAnalysed();

    if (this->analysed) {
        this->measure_Y = *(stream->getStreamData());

//        // pre-initialise paths with the correct number of elements
//        quint32 iterations = this->sampleRate.getSamplesPerCycle() * NUMBER_OF_CYCLES_TO_ANALYSE;

//        for (int i = 0; i < 8; i++) {
//            if (paths[i].length() <= 1) {
//                for (quint32 t = 0; t < iterations; t++) {
//                    paths[i].lineTo(0.001 * t, 0.001 * t);
//                }
//            }
//        }


        //TODO: generate this (the entire object?) during analysis, then pass to UI thread
        quint32 iterations = this->sampleRate.getSamplesPerCycle() * NUMBER_OF_CYCLES_TO_ANALYSE;

        for (quint32 i = 0; i < iterations; i++) {
            Sample sample = *stream->getSampleAt(i);
            sampledData.append(sample);
        }

        this->maxInstantaneousCurrent = stream->getMaxInstantaneous(Stream::Current);
        this->maxInstantaneousVoltage = stream->getMaxInstantaneous(Stream::Voltage);
    }
}

QPainterPath *StreamTableRow::getPainterPath(QPainterPath *path, int powerSystemQuantity, int phase)
{
    quint32 iterations = sampledData.size();//sampleRate.getSamplesPerCycle() * NUMBER_OF_CYCLES_TO_ANALYSE;
    qreal Ts = sampleRate.getTimestep();

    for (quint32 t = 0; t < iterations; t++) {
        qreal tMilliseconds = (qreal) t * Ts * 1000.0;

        if (powerSystemQuantity == Stream::Current) {
            if (t == 0) {
                path->setElementPositionAt(t, tMilliseconds, (qreal) -1.0 * sampledData[t].current[phase] * LE_IED.S1.MUnn.IEC_61850_9_2LETCTR_1.Amp.sVC.scaleFactor);
                //path->moveTo(tMilliseconds, (qreal) -1.0 * sampledData[t].current[phase] * LE_IED.S1.MUnn.IEC_61850_9_2LETCTR_1.Amp.sVC.scaleFactor);
            }
            else {
                path->setElementPositionAt(t, tMilliseconds, (qreal) -1.0 * sampledData[t].current[phase] * LE_IED.S1.MUnn.IEC_61850_9_2LETCTR_1.Amp.sVC.scaleFactor);
                //path->lineTo(tMilliseconds, (qreal) -1.0 * sampledData[t].current[phase] * LE_IED.S1.MUnn.IEC_61850_9_2LETCTR_1.Amp.sVC.scaleFactor);
            }
        }
        else if (powerSystemQuantity == Stream::Voltage) {
            if (t == 0) {
                path->setElementPositionAt(t, tMilliseconds, (qreal) -1.0 * sampledData[t].voltage[phase] * LE_IED.S1.MUnn.IEC_61850_9_2LETVTR_1.Vol.sVC.scaleFactor);
                //path->moveTo(tMilliseconds, (qreal) -1.0 * sampledData[t].voltage[phase] * LE_IED.S1.MUnn.IEC_61850_9_2LETVTR_1.Vol.sVC.scaleFactor);
            }
            else {
                path->setElementPositionAt(t, tMilliseconds, (qreal) -1.0 * sampledData[t].voltage[phase] * LE_IED.S1.MUnn.IEC_61850_9_2LETVTR_1.Vol.sVC.scaleFactor);
                //path->lineTo(tMilliseconds, (qreal) -1.0 * sampledData[t].voltage[phase] * LE_IED.S1.MUnn.IEC_61850_9_2LETVTR_1.Vol.sVC.scaleFactor);
            }
        }

        //qDebug() << (qreal) t * Ts << (qreal) samples[t].current[phase] * 0.01;
    }

    return path;
}
