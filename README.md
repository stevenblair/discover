# discover - a real-time monitoring and analysis tool for IEC 61850-9-2 LE Sampled Values #

*The code is a work in progress. Several features are missing.*

## Overview ##

This program uses the open source [rapid61850](https://github.com/stevenblair/rapid61850) project to listen to Sampled Value streams in real-time. Sampled Value data are put through the measurement and analysis code by [Andrew Roscoe](http://personal.strath.ac.uk/andrew.j.roscoe/), described in [this paper](http://dx.doi.org/10.1049/iet-gtd.2008.0517). This provides detailed information on the voltage and current fundamental magnitude and phase, harmonics, power flow, etc. Frequency analysis is done using the resampled DFT method described in [this paper](http://dx.doi.org/10.1049/cp.2011.0140), which is very efficient and offers low spectral leakage.

The voltage and current information is visualised using a Qt-based GUI. The program is designed to be lightweight, efficient, open source, and cross-platform.

## Implemented features ##

 - Capture multiple SV streams
 - Supports 50 or 60 Hz nominal frequency, and 80 or 256 samples per cycle
 - Performs detailed analysis on voltage and current
 - Displays a summary of voltage, current, and power
 - Plots of fundamental voltage and current phasors
 - Plots of voltage and current waveforms
 - Supports multiple network interfaces
 - Resampled DFT for frequency analysis - efficient, and with low spectral leakage
 - Runs on Windows, OS X, and Linux

## Features to be added ##

 - Power flow analysis
 - Symmetrical component visualisation
 - Power quality analysis
 - Update SV stream status

# Installation #

 - Install [Qt Creator](http://qt-project.org/downloads) and a compiler for your platform. So far, the code has been tested with Qt Creator 4.8.0 (or 4.8.1) on Windows 7 64-bit, Mac OS X Mountain Lion, and Ubuntu 12.04 64-bit.
 - Download or clone the code from https://github.com/stevenblair/discover.

Alternatively, the pre-built Windows binary, in the `/release` directory, can be executed without Qt Creator. The WinPcap runtime must be installed (if you have Wireshark installed, this includes WinPcap) and the two DLLs must be in the same directory as the .exe file.

The program can be tested using the [rapid61850](https://github.com/stevenblair/rapid61850) project. Point the code generator to  the `LE.scd` SCD file in the repo. Then build and run the `main_SV_LE.c` example file.