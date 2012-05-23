#include <QtGui/QApplication>
#include "mainwindow.h"
#include "commsthread.h"

#include "rapid61850/iec61850.h"

CommsThread commsThread;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    qRegisterMetaType<LE_IED_MUnn_PhsMeas1>("LE_IED_MUnn_PhsMeas1");

    //QObject::connect(&commsThread, SIGNAL(updateUI()), &window, SLOT(updateRenderArea()));
    //QObject::connect(&(commsThread.lom), SIGNAL(appendMessage(QString)), &window, SLOT(append(QString)));
    QObject::connect(&commsThread, SIGNAL(addInterface(int, QString)), &w, SLOT(addInterface(int, QString)));
    QObject::connect(&commsThread, SIGNAL(addSample(QString, QString, LE_IED_MUnn_PhsMeas1, quint16)), w.getStreamTableModel(), SLOT(addStreamDataSlot(QString, QString, LE_IED_MUnn_PhsMeas1, quint16)));
    QObject::connect(w.getStreamTableModel(), SIGNAL(resizeColumnsToContents()), w.getStreamTableView(), SLOT(resizeColumnsToContents()));

    commsThread.start();
    w.show();
    
    return a.exec();
}
