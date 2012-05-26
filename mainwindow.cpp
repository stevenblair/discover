#include "mainwindow.h"
#include <QHeaderView>
#include <QDebug>

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

    streamsLayout->addWidget(tableView);
    connect(tableView->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), this->tableModel, SLOT(getSelectedSvID(const QItemSelection &, const QItemSelection &)));


    //scene->addText("hello world");
    mainLayout->addLayout(networkInterfaceLayout, 0);
    //mainLayout->addWidget(tableView, 1, Qt::AlignCenter);
    mainLayout->addLayout(streamsLayout);
    mainLayout->addLayout(graphLayout, 0);

    currentPhasorScene = new PhasorScene(tableModel);
    voltagePhasorScene = new PhasorScene(tableModel);
    connect(tableModel, SIGNAL(streamSelected(QString)), currentPhasorScene, SLOT(streamSelectionChanged(QString)));
    connect(tableModel, SIGNAL(streamSelected(QString)), voltagePhasorScene, SLOT(streamSelectionChanged(QString)));

    currentPhasorView = new QGraphicsView;
    voltagePhasorView = new QGraphicsView;
    currentPhasorView->setScene(currentPhasorScene);
    voltagePhasorView->setScene(voltagePhasorScene);
    graphLayout->addWidget(currentPhasorView, 0, 0, 1, 1, Qt::AlignCenter);
    graphLayout->addWidget(voltagePhasorView, 1, 0, 1, 1, Qt::AlignCenter);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    //currentPhasorView->show();
    tableView->resizeColumnsToContents();

    setWindowTitle(tr("discover"));
    setMinimumWidth(700);
}

MainWindow::~MainWindow()
{
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
