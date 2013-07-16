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

#ifndef SAMPLE_H
#define SAMPLE_H

#include <QtGlobal>
extern "C" {
#include "rapid61850/iec61850.h"
}

#define VOLTAGE_SIGNALS     4
#define CURRENT_SIGNALS     4
#define TOTAL_SIGNALS       8

class Sample
{
public:
    Sample() {}

    /**
      * Provides a mapping of voltages and currents to an index value.
      */
    qint32 getSample(int index) {
        switch (index) {
        case 0:
            return voltage[0];
        case 1:
            return voltage[1];
        case 2:
            return voltage[2];
        case 3:
            return voltage[3];
        case 4:
            return current[0];
        case 5:
            return current[1];
        case 6:
            return current[2];
        case 7:
            return current[3];
        default:
            return 0;
        }
    }

    qreal getSampleValue(int index) {
        switch (index) {
        case 0:
            return voltage[0] * LE_IED.S1.MUnn.IEC_61850_9_2LETVTR_1.Vol.sVC.scaleFactor;
        case 1:
            return voltage[1] * LE_IED.S1.MUnn.IEC_61850_9_2LETVTR_2.Vol.sVC.scaleFactor;
        case 2:
            return voltage[2] * LE_IED.S1.MUnn.IEC_61850_9_2LETVTR_3.Vol.sVC.scaleFactor;
        case 3:
            return voltage[3] * LE_IED.S1.MUnn.IEC_61850_9_2LETVTR_4.Vol.sVC.scaleFactor;
        case 4:
            return current[0] * LE_IED.S1.MUnn.IEC_61850_9_2LETCTR_1.Amp.sVC.scaleFactor;
        case 5:
            return current[1] * LE_IED.S1.MUnn.IEC_61850_9_2LETCTR_2.Amp.sVC.scaleFactor;
        case 6:
            return current[2] * LE_IED.S1.MUnn.IEC_61850_9_2LETCTR_3.Amp.sVC.scaleFactor;
        case 7:
            return current[3] * LE_IED.S1.MUnn.IEC_61850_9_2LETCTR_4.Amp.sVC.scaleFactor;
        default:
            return 0.0;
        }
    }

    qint16 smpCount;
    qint32 voltage[VOLTAGE_SIGNALS];
    quint32 voltageQuality[VOLTAGE_SIGNALS];
    qint32 current[CURRENT_SIGNALS];
    quint32 currentQuality[CURRENT_SIGNALS];
};

#endif // SAMPLE_H
