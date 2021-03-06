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

#include <QTranslator>
#include <QLocale>
#include <qglobal.h>
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    #include <QtWidgets/QApplication>
#else
    #include <QtGui/QApplication>
#endif

#include "MainWindow.h"
#include "CommsThread.h"

#include "rapid61850/iec61850.h"

CommsThread commsThread;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setApplicationName("Discover");
    a.setOrganizationName(a.applicationName());
    a.setApplicationVersion("1.2.0");
    a.setOrganizationDomain("https://github.com/bravikov/discover/tree/bravikov");

    QTranslator translator;
    bool ok = translator.load(":/Translations/discover_" + QLocale::system().name());
    if (ok) {
        a.installTranslator(&translator);
    }
    else {
        qDebug() << "Translation is not loaded.";
    }

    qRegisterMetaType<LE_IED_MUnn_PhsMeas1>("LE_IED_MUnn_PhsMeas1");

    MainWindow w;

    QObject::connect(&commsThread, SIGNAL(addInterface(int, QString)), &w, SLOT(addInterface(int, QString)));
    QObject::connect(w.getStreamTableModel(), SIGNAL(resizeColumnsToContents()), w.getStreamTableView(), SLOT(resizeColumnsToContents()));

    commsThread.start();
    w.show();
    
    return a.exec();
}
