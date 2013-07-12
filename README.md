# discover - a real-time monitoring and analysis tool for IEC 61850-9-2LE Sampled Values #

*The code is a work in progress. Several features are missing.*

## Overview ##

This program uses the open source [rapid61850](https://github.com/stevenblair/rapid61850) project to listen to Sampled Value streams in real-time. Sampled Value data are put through the measurement and analysis code by [Andrew Roscoe](http://personal.strath.ac.uk/andrew.j.roscoe/), described in [this paper](http://dx.doi.org/10.1049/iet-gtd.2008.0517). This provides detailed information on the voltage and current fundamental magnitude and phase, harmonics, power flow, etc. Frequency analysis is done using the resampled DFT method described in [this paper](http://dx.doi.org/10.1049/cp.2011.0140), which is very efficient and offers low spectral leakage.

The voltage and current information is visualised using a Qt-based GUI. The program is designed to be lightweight, efficient, open source, and cross-platform (although it has only been tested on Windows so far).

## Implemented features ##

 - Capture multiple SV streams
 - Supports 50 or 60 Hz nominal frequency, and 80 or 256 samples per cycle
 - Performs detailed analysis on voltage and current
 - Displays a summary of voltage, current, and power
 - Plots of fundamental voltage and current phasors
 - Plots of voltage and current waveforms
 - Supports multiple network interfaces
 - Resampled DFT for frequency analysis - efficient, and with low spectral leakage

## Features to be added ##

 - Power flow analysis
 - Symmetrical component visualisation
 - Power quality analysis
 - Update SV stream status

# Installation #

 - Install [Qt Creator](http://qt-project.org/downloads) and a compiler. So far, the code has been tested with Qt Creator 4.8.0 and MinGW 3.18.
 - Download or clone the code from https://github.com/stevenblair/discover.

Alternatively, the pre-built Windows binary can be executed without Qt Creator. The WinPcap runtime must be installed (if you have Wireshark installed, this includes WinPcap) and the two DLLs must be in the same directory as the .exe file.