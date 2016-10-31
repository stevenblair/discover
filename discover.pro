#
# discover - a real-time monitoring and analysis tool for IEC 61850-9-2LE Sampled Values
#
# Copyright (c) 2013 Steven Blair
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#

QT       += core gui

TARGET = discover
TEMPLATE = app
QT += widgets

#CONFIG += console
QMAKE_CFLAGS_RELEASE	= -O3
CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT

SOURCES += main.cpp\
    rapid61850/svEncodePacket.c \
    rapid61850/svEncodeBasic.c \
    rapid61850/svEncode.c \
    rapid61850/svDecodePacket.c \
    rapid61850/svDecodeBasic.c \
    rapid61850/svDecode.c \
    rapid61850/sv.c \
    rapid61850/ied.c \
    rapid61850/iec61850.c \
    rapid61850/gseEncodePacket.c \
    rapid61850/gseEncodeBasic.c \
    rapid61850/gseEncode.c \
    rapid61850/gseDecodePacket.c \
    rapid61850/gseDecodeBasic.c \
    rapid61850/gseDecode.c \
    rapid61850/gse.c \
    rapid61850/encodePacket.c \
    rapid61850/decodePacket.c \
    rapid61850/datatypes.c \
    rapid61850/ctypes.c \
    measure/rtGetNaN.cpp \
    measure/rtGetInf.cpp \
    measure/rt_nonfinite.cpp \
    measure/measure_parameters.cpp \
    measure/measure.cpp \
    ProxyItemView.cpp \
    PhasorPlotTab.cpp \
    FrequencyTab.cpp \
    FrequencyScene.cpp \
    measure/measure_data.cpp \
    TreeItem.cpp \
    PowerTreeModel.cpp \
    PowerTab.cpp \
    MainWindow.cpp \
    CommsThread.cpp \
    PhasorScene.cpp \
    PhasorView.cpp \
    PlotScene.cpp \
    PlotView.cpp \
    Stream.cpp \
    StreamManager.cpp \
    StreamTableRow.cpp \
    TabViewWidget.cpp \
    SampleRate.cpp \
    StreamTableModel.cpp \
    FrequencyView.cpp

HEADERS  += \
    rapid61850/svPacketData.h \
    rapid61850/svEncodeBasic.h \
    rapid61850/svEncode.h \
    rapid61850/svDecodeBasic.h \
    rapid61850/svDecode.h \
    rapid61850/sv.h \
    rapid61850/ied.h \
    rapid61850/iec61850.h \
    rapid61850/gsePacketData.h \
    rapid61850/gseEncodeBasic.h \
    rapid61850/gseEncode.h \
    rapid61850/gseDecodeBasic.h \
    rapid61850/gseDecode.h \
    rapid61850/gse.h \
    rapid61850/encodePacket.h \
    rapid61850/decodePacket.h \
    rapid61850/datatypes.h \
    rapid61850/ctypes.h \
    measure/rtwtypes.h \
    measure/rtGetNaN.h \
    measure/rtGetInf.h \
    measure/rt_nonfinite.h \
    measure/rt_defines.h \
    measure/measure_private.h \
    measure/measure_parameters.h \
    measure/measure.h \
    measure/measure_types.h \
    ProxyItemView.h \
    PhasorPlotTab.h \
    FrequencyTab.h \
    FrequencyScene.h \
    TreeItem.h \
    PowerTreeModel.h \
    PowerTab.h \
    CommsThread.h \
    MainWindow.h \
    StatusColumnDelegate.h \
    StreamManager.h \
    Stream.h \
    PlotView.h \
    PlotScene.h \
    PhasorView.h \
    PhasorScene.h \
    Sample.h \
    SampleRate.h \
    StreamTableModel.h \
    StreamTableRow.h \
    TabviewWidget.h \
    FrequencyView.h \
    settings.h

#contains(QT_CONFIG, opengl):QT += opengl

INCLUDEPATH += "$$_PRO_FILE_PWD_/Include"

win32 {
    LIBS += -L"$$_PRO_FILE_PWD_/Lib" -lwpcap
    RC_FILE += icon.rc
}
macx {
    LIBS += -L"$$_PRO_FILE_PWD_/Lib" -lpcap
}
unix {
    LIBS += -L"$$_PRO_FILE_PWD_/Lib" -lpcap
}
