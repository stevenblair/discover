#include "mainwindow.h"
#include "statuscolumndelegate.h"
#include <QHeaderView>
#include <QDebug>
#include <QDesktopWidget>
#include <QItemSelectionModel>

#include <QDoubleSpinBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *networkInterfaceLayout = new QHBoxLayout;
    QVBoxLayout *streamsLayout = new QVBoxLayout;
    tabWidget = new QTabWidget;
    phasorPlotWidget = new PhasorPlotWidget;

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
    tableView->setMinimumHeight(200);

    phasorPlotView = new PhasorPlotView(phasorPlotWidget);
    phasorPlotView->setModel(tableModel);

    // TODO: is this necessary? where do PersistentSelectionModels fit in?
    QItemSelectionModel *itemSelectionModel = new QItemSelectionModel(tableModel);
    phasorPlotView->setSelectionModel(itemSelectionModel);
    tableView->setSelectionModel(itemSelectionModel);

    streamsLayout->addWidget(tableView);
    connect(tableView->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), this->tableModel, SLOT(getSelectedSvID(const QItemSelection &, const QItemSelection &)));
    connect(itemSelectionModel, SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), this->phasorPlotView, SLOT(selectionChanged(QItemSelection &,QItemSelection &)));

    mainLayout->addLayout(networkInterfaceLayout, 0);
    mainLayout->addLayout(streamsLayout);
    mainLayout->addWidget(tabWidget, 0);/*

    currentPhasorScene = new CurrentPhasorScene(tableModel);
    voltagePhasorScene = new VoltagePhasorScene(tableModel);
    connect(tableModel, SIGNAL(streamSelected(Stream*)), currentPhasorScene, SLOT(streamSelectionChanged(Stream*)));    // TODO: connect directly between TableView and Phasors?
    connect(tableModel, SIGNAL(streamSelected(Stream*)), voltagePhasorScene, SLOT(streamSelectionChanged(Stream*)));

    currentPhasorView = new PhasorView;
    voltagePhasorView = new PhasorView;

    currentPlotScene = new CurrentPlotScene();
    voltagePlotScene = new VoltagePlotScene();

    currentPlotView = new PlotView;
    voltagePlotView = new PlotView;
    currentPlotView->setScene(currentPlotScene);
    voltagePlotView->setScene(voltagePlotScene);
    connect(tableModel, SIGNAL(streamSelected(Stream*)), currentPlotScene, SLOT(streamSelectionChanged(Stream*)));
    connect(tableModel, SIGNAL(streamSelected(Stream*)), voltagePlotScene, SLOT(streamSelectionChanged(Stream*)));*/

    tabWidget->addTab(phasorPlotWidget, tr("Phasors and waveforms"));
    tabWidget->addTab(new QDoubleSpinBox(), tr("Power quality"));

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    //currentPhasorView->show();
    tableView->resizeColumnsToContents();

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
