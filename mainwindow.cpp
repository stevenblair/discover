#include "mainwindow.h"
#include <QHeaderView>

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

    //scene = new QGraphicsScene;
    //scene->addText("hello world");

    //currentPhasor->setScene(scene);
    //graphLayout->addWidget(currentPhasor->viewport());

    mainLayout->addLayout(networkInterfaceLayout, 0);
    //mainLayout->addWidget(tableView, 1, Qt::AlignCenter);
    mainLayout->addLayout(streamsLayout);
    mainLayout->addLayout(graphLayout, 0);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

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
