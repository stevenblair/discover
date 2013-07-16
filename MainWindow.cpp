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

#include "MainWindow.h"
#include "StatusColumnDelegate.h"
#include <QHeaderView>
#include <QDebug>
#include <QDesktopWidget>
#include <QItemSelectionModel>

#include <QDoubleSpinBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    QHBoxLayout *networkInterfaceLayout = new QHBoxLayout;
    QVBoxLayout *streamsLayout = new QVBoxLayout;
    tabWidget = new QTabWidget(centralWidget);

    phasorPlotTab = new PhasorPlotTab(tabWidget);
    frequencyTab = new FrequencyTab(tabWidget);
    powerTab = new PowerTab(tabWidget);

    interfaceComboBox = new QComboBox;
    networkInterfaceLabel = new QLabel(tr("Network interface:"));
    networkInterfaceLayout->addWidget(networkInterfaceLabel);
    networkInterfaceLayout->addWidget(interfaceComboBox, 1);

    tableModel = new StreamTableModel(this);
    tableView = new QTableView;
    tableView->setModel(tableModel);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->horizontalHeader()->setHighlightSections(false);
    tableView->verticalHeader()->hide();
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView->setItemDelegateForColumn(STREAM_TABLE_COLUMNS_STATUS, new StatusColumnDelegate());
    tableView->setMinimumHeight(TABLE_VIEW_MINIMUM_HEIGHT);

    phasorPlotTabView = new ProxyItemView(phasorPlotTab, tableModel);
    frequencyTabView = new ProxyItemView(frequencyTab, tableModel);
    powerTabView = new ProxyItemView(powerTab, tableModel);

    // TODO: is this necessary? where do PersistentSelectionModels fit in?
    QItemSelectionModel *itemSelectionModel = new QItemSelectionModel(tableModel);
    phasorPlotTabView->setSelectionModel(itemSelectionModel);
    frequencyTabView->setSelectionModel(itemSelectionModel);
    tableView->setSelectionModel(itemSelectionModel);
    powerTabView->setSelectionModel(itemSelectionModel);

    streamsLayout->addWidget(tableView);
    connect(itemSelectionModel, SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), this->phasorPlotTabView, SLOT(selectionChanged(const QItemSelection &, const QItemSelection &)));

    mainLayout->addLayout(networkInterfaceLayout, 0);
    mainLayout->addLayout(streamsLayout, 1);
    mainLayout->addWidget(tabWidget, 0);

    tabWidget->addTab(phasorPlotTab, tr("Phasors and waveforms"));
    tabWidget->addTab(frequencyTab, tr("Frequency analysis"));
    tabWidget->addTab(new QWidget(), tr("Symmetrical components"));
    tabWidget->addTab(powerTab, tr("Power analysis"));
    tabWidget->addTab(new QWidget(), tr("Power quality"));

    //currentPhasorView->show();
    tableView->resizeColumnsToContents();

    setCentralWidget(centralWidget);

    setWindowTitle(tr("discover"));
    setMinimumWidth(1000);
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );

    commsThread.getStreamManager()->setTableModelPtr(tableModel);

    connect(interfaceComboBox, SIGNAL(currentIndexChanged(int)), &commsThread, SLOT(setNetworkInterface(int)));
    connect(&commsThread, SIGNAL(networkInterfaceStopped()), tableModel, SLOT(networkInterfaceStopped()));
    connect(tableModel, SIGNAL(streamTableEmpty()), &commsThread, SLOT(startNetworkInterface()));
}

MainWindow::~MainWindow()
{
    // kill commsThread gracefully
    commsThread.terminate();
    commsThread.wait();
}

StreamTableModel *MainWindow::getStreamTableModel()
{
    return tableModel;
}

QTableView *MainWindow::getStreamTableView()
{
    return tableView;
}

void MainWindow::addInterface(int value, QString name) {
    interfaceComboBox->addItem(name, value);
}
