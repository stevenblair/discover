#include "samplerate.h"

SampleRate::SampleRate()
{
    known = false;
    this->nominalFrequency = NominalFreq50Hz;
    this->samplesPerCycle = Samples80;
}

SampleRate::SampleRate(SampleRate::NominalFrequency nominalFrequency, SampleRate::SamplesPerCycle samplesPerCycle)
{
    known = true;
    this->nominalFrequency = nominalFrequency;
    this->samplesPerCycle = samplesPerCycle;
}

qint32 SampleRate::getSamplesPerSecond()
{
    return (qint32) (nominalFrequency * samplesPerCycle);
}

SampleRate::NominalFrequency SampleRate::getNominalFrequency()
{
    return nominalFrequency;
}

SampleRate::SamplesPerCycle SampleRate::getSamplesPerCycle()
{
    return samplesPerCycle;
}

bool SampleRate::isKnown()
{
    return known;
}

qreal SampleRate::getTimestep()
{
    return 1.0 / ((qreal) nominalFrequency * samplesPerCycle);
}


void SampleRate::setSampleRate(SampleRate::NominalFrequency nominalFrequency, SampleRate::SamplesPerCycle samplesPerCycle)
{
    known = true;
    this->nominalFrequency = nominalFrequency;
    this->samplesPerCycle = samplesPerCycle;
}
