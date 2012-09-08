/**
 * discover - a real-time monitoring and analysis tool for IEC 61850-9-2LE Sampled Values
 *
 * Copyright (c) 2012 Andrew Roscoe, Steven Blair
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

#ifndef MEASURE_PARAMETERS_H
#define MEASURE_PARAMETERS_H

#include "measure.h"

extern const Parameters_measure measure_P_50Hz_80_samples_per_cycle;
extern const Parameters_measure measure_P_60Hz_80_samples_per_cycle;
extern const Parameters_measure measure_P_50Hz_256_samples_per_cycle;
extern const Parameters_measure measure_P_60Hz_256_samples_per_cycle;

#endif // MEASURE_PARAMETERS_H
