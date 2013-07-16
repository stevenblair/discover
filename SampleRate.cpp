/**
 * discover - a real-time monitoring and analysis tool for IEC 61850-9-2LE Sampled Values
 *
 * Copyright (c) 2012 Steven Blair
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

#include "SampleRate.h"

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

quint32 SampleRate::getSamplesPerSecond()
{
    return (quint32) (nominalFrequency * samplesPerCycle);
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
