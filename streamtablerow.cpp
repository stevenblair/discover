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
    }
}
