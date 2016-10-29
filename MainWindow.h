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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qglobal.h>
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    #include <QtWidgets/QMainWindow>
#else
    #include <QtGui/QMainWindow>
#endif

#include <QTableView>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QGraphicsView>
#include <QTableWidget>
#include "ProxyItemView.h"
#include "StreamTableModel.h"
#include "CommsThread.h"
#include "PhasorPlotTab.h"
#include "FrequencyTab.h"
#include "PowerTab.h"
#include <QCloseEvent>

extern CommsThread commsThread;

#define TABLE_VIEW_MINIMUM_HEIGHT   150

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    StreamTableModel *getStreamTableModel();
    QTableView *getStreamTableView();

public slots:
    void addInterface(int value, QString name);

protected:
    void closeEvent(QCloseEvent *event);

private:
    QLabel *networkInterfaceLabel;
    QComboBox *interfaceComboBox;

    // the model, and its views
    StreamTableModel *tableModel;
    QTableView *tableView;
    ProxyItemView *phasorPlotTabView;
    ProxyItemView *frequencyTabView;
    ProxyItemView *powerTabView;

    // the tab container, and the tabs
    QTabWidget *tabWidget;
    PhasorPlotTab *phasorPlotTab;
    FrequencyTab *frequencyTab;
    PowerTab *powerTab;

    void saveSettings();
    void restoreSettings();
};

#endif // MAINWINDOW_H
