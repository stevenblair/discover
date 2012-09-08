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

#include "measure.h"
#include "measure_private.h"

const ConstParam_measure measure_ConstP = {

  { 1.0, 0.99518472667219693, 0.98078528040323043, 0.95694033573220882,
    0.92387953251128674, 0.881921264348355, 0.83146961230254524,
    0.773010453362737, 0.70710678118654757, 0.63439328416364549,
    0.55557023301960229, 0.47139673682599781, 0.38268343236508984,
    0.29028467725446233, 0.19509032201612833, 0.09801714032956077,
    6.123233995736766E-17, -0.098017140329560645, -0.19509032201612819,
    -0.29028467725446216, -0.38268343236508973, -0.4713967368259977,
    -0.555570233019602, -0.63439328416364538, -0.70710678118654746,
    -0.773010453362737, -0.83146961230254535, -0.88192126434835494,
    -0.92387953251128674, -0.95694033573220882, -0.98078528040323043,
    -0.99518472667219682, -1.0, -0.99518472667219693, -0.98078528040323043,
    -0.95694033573220894, -0.92387953251128685, -0.881921264348355,
    -0.83146961230254546, -0.7730104533627371, -0.70710678118654768,
    -0.63439328416364593, -0.55557023301960218, -0.47139673682599786,
    -0.38268343236509034, -0.29028467725446244, -0.19509032201612866,
    -0.098017140329560451 }
};
