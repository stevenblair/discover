#include "mainwindow.h"
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    tableModel = new StreamTableModel(this);

    tableView = new QTableView;
    tableView->setModel(tableModel);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->horizontalHeader()->setHighlightSections(false);
    tableView->verticalHeader()->hide();
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    interfaceComboBox = new QComboBox;
    networkInterfaceLabel = new QLabel(tr("Network interface:"));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *networkInterfaceLayout = new QHBoxLayout;
    QVBoxLayout *streamsLayout = new QVBoxLayout;
    QGridLayout *graphLayout = new QGridLayout;

    networkInterfaceLayout->addWidget(networkInterfaceLabel);
    networkInterfaceLayout->addWidget(interfaceComboBox, 1);

    streamsLayout->addWidget(tableView);

    mainLayout->addLayout(networkInterfaceLayout, 0);
    //mainLayout->addWidget(tableView, 1, Qt::AlignCenter);
    mainLayout->addLayout(streamsLayout);
    mainLayout->addLayout(graphLayout, 0);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);

    setCentralWidget(centralWidget);

    /*LE_IED_MUnn_PhsMeas1 dataset = {{0}};
    tableModel->addStreamData("MU01", "01-00-00-00-00-00", &dataset, 0);
    tableModel->addStreamData("MU02", "01-00-00-00-00-00", &dataset, 0);
    tableModel->addStreamData("MU03", "01-00-00-00-00-00", &dataset, 0);
    tableModel->addStreamData("MU02", "01-00-00-00-00-00", &dataset, 0);
    tableModel->addStreamData("MU00", "01-00-00-00-00-00", &dataset, 0);*/

    tableView->resizeColumnsToContents();

    setWindowTitle(tr("discover"));
    setMinimumWidth(600);
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
