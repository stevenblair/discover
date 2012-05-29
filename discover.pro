#-------------------------------------------------
#
# Project created by QtCreator 2012-05-22T17:24:19
#
#-------------------------------------------------

QT       += core gui

TARGET = discover
TEMPLATE = app

CONFIG += console
QMAKE_CFLAGS_RELEASE	= -O3

SOURCES += main.cpp\
        mainwindow.cpp \
    stream.cpp \
    sample.cpp \
    streamtablemodel.cpp \
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
    commsthread.cpp \
    phasorscene.cpp \
    phasorview.cpp \
    statuscolumndelegate.cpp \
    plotview.cpp \
    measure/rtGetNaN.cpp \
    measure/rtGetInf.cpp \
    measure/rt_nonfinite.cpp \
    measure/measure_parameters.cpp \
    measure/measure.cpp

HEADERS  += mainwindow.h \
    stream.h \
    sample.h \
    streamtablemodel.h \
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
    commsthread.h \
    phasorscene.h \
    phasorview.h \
    statuscolumndelegate.h \
    plotview.h \
    measure/rtwtypes.h \
    measure/rtGetNaN.h \
    measure/rtGetInf.h \
    measure/rt_nonfinite.h \
    measure/rt_defines.h \
    measure/measure_private.h \
    measure/measure_parameters.h \
    measure/measure.h \
    measure/measure_types.h

# winpcap
INCLUDEPATH += C:/Users/Steven/discover/Include
LIBS += -L C:/Users/Steven/discover/Lib -lwpcap
