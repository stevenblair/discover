#include "streamtablerow.h"

StreamTableRow::StreamTableRow(Stream *stream, QObject *parent) : QObject(parent)
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
    }
}
