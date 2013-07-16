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

#ifndef SAMPLERATE_H
#define SAMPLERATE_H

#include <QGlobalStatic>
#include <QtCore/qmath.h>
#include "Sample.h"

#define SAMPLES_50HZ_80_PER_CYCLE   4000
#define SAMPLES_60HZ_80_PER_CYCLE   4800
#define SAMPLES_50HZ_256_PER_CYCLE  12800
#define SAMPLES_60HZ_256_PER_CYCLE  15360                       // 256 samples/cycle * 60 cycles
#define MAX_SAMPLES                 SAMPLES_60HZ_256_PER_CYCLE

class SampleRate
{
public:
    enum NominalFrequency {NominalFreq50Hz = 50, NominalFreq60Hz = 60};
    enum SamplesPerCycle {Samples80 = 80, Samples256 = 256};

    SampleRate();
    SampleRate(NominalFrequency nominalFrequency, SamplesPerCycle samplesPerCycle);

    void setSampleRate(SampleRate::NominalFrequency nominalFrequency, SampleRate::SamplesPerCycle samplesPerCycle);
    quint32 getSamplesPerSecond();
    NominalFrequency getNominalFrequency();
    SamplesPerCycle getSamplesPerCycle();
    bool isKnown();
    qreal getTimestep();
    quint32 getLargestPowerOfTwo() {
        if (this->isKnown()) {
            qreal sampleRate = (qreal) this->getSamplesPerSecond();

            return qPow(2.0, (qreal) qFloor(qLn(sampleRate) / qLn(2.0)));
        }

        return 8;
    }

private:
    bool known;
    NominalFrequency nominalFrequency;
    SamplesPerCycle samplesPerCycle;
};

#endif // SAMPLERATE_H
