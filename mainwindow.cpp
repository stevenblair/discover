#include "mainwindow.h"
#include "statuscolumndelegate.h"
#include <QHeaderView>
#include <QDebug>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *networkInterfaceLayout = new QHBoxLayout;
    QVBoxLayout *streamsLayout = new QVBoxLayout;
    QGridLayout *graphLayout = new QGridLayout;

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

    streamsLayout->addWidget(tableView);
    connect(tableView->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), this->tableModel, SLOT(getSelectedSvID(const QItemSelection &, const QItemSelection &)));

    mainLayout->addLayout(networkInterfaceLayout, 0);
    mainLayout->addLayout(streamsLayout);
    mainLayout->addLayout(graphLayout, 0);

    currentPhasorScene = new CurrentPhasorScene(tableModel);
    voltagePhasorScene = new VoltagePhasorScene(tableModel);
    connect(tableModel, SIGNAL(streamSelected(Stream*)), currentPhasorScene, SLOT(streamSelectionChanged(Stream*)));    // TODO: connect directly between TableView and Phasors?
    connect(tableModel, SIGNAL(streamSelected(Stream*)), voltagePhasorScene, SLOT(streamSelectionChanged(Stream*)));

    currentPhasorView = new PhasorView;
    voltagePhasorView = new PhasorView;
    currentPlotView = new PlotView;
    voltagePlotView = new PlotView;

    /*currentPhasorView->centerOn(0.0, 0.0);
    voltagePhasorView->centerOn(0.0, 0.0);
    currentPhasorView->fitInView(-PHASOR_VIEW_MAX_SIZE, -PHASOR_VIEW_MAX_SIZE, PHASOR_VIEW_MAX_SIZE, PHASOR_VIEW_MAX_SIZE);
    voltagePhasorView->fitInView(-PHASOR_VIEW_MAX_SIZE, -PHASOR_VIEW_MAX_SIZE, PHASOR_VIEW_MAX_SIZE, PHASOR_VIEW_MAX_SIZE);*/
    currentPhasorView->setScene(currentPhasorScene);
    voltagePhasorView->setScene(voltagePhasorScene);
    graphLayout->addWidget(voltagePhasorView, 0, 0, Qt::AlignCenter);
    graphLayout->addWidget(currentPhasorView, 1, 0, Qt::AlignCenter);
    graphLayout->addWidget(currentPlotView, 0, 1, Qt::AlignCenter);
    graphLayout->addWidget(voltagePlotView, 1, 1, Qt::AlignCenter);
    graphLayout->setColumnStretch(0, 0);
    graphLayout->setColumnStretch(1, 1);

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
