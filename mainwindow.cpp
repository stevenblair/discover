#include "mainwindow.h"
#include "statuscolumndelegate.h"
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

    // TODO: is this necessary? where do PersistentSelectionModels fit in?
    QItemSelectionModel *itemSelectionModel = new QItemSelectionModel(tableModel);
    phasorPlotTabView->setSelectionModel(itemSelectionModel);
    tableView->setSelectionModel(itemSelectionModel);

    streamsLayout->addWidget(tableView);
    connect(itemSelectionModel, SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), this->phasorPlotTabView, SLOT(selectionChanged(const QItemSelection &, const QItemSelection &)));

    mainLayout->addLayout(networkInterfaceLayout, 0);
    mainLayout->addLayout(streamsLayout, 1);
    mainLayout->addWidget(tabWidget, 0);

    tabWidget->addTab(phasorPlotTab, tr("Phasors and waveforms"));
    tabWidget->addTab(new QGraphicsView(), tr("Sequence components"));
    tabWidget->addTab(new QGraphicsView(), tr("Frequency analysis"));
    tabWidget->addTab(new QGraphicsView(), tr("Power analysis"));
    tabWidget->addTab(new QGraphicsView(), tr("Power quality"));

    //currentPhasorView->show();
    tableView->resizeColumnsToContents();

    setCentralWidget(centralWidget);

    setWindowTitle(tr("discover"));
    //setMinimumWidth(700);
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
    //connect(interfaceComboBox, SIGNAL(currentIndexChanged(int)), tableModel, SLOT(networkInterfaceChanged()));
    connect(&commsThread, SIGNAL(networkInterfaceStopped()), tableModel, SLOT(networkInterfaceStopped()));
    connect(tableModel, SIGNAL(streamTableEmpty()), &commsThread, SLOT(startNetworkInterface()));
}

MainWindow::~MainWindow()
{
    // TODO: kill commsThread gracefully
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
