#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    tableModel = new StreamTableModel(this);

    tableView = new QTableView;
    tableView->setModel(tableModel);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->setSortingEnabled(true);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tableView, 0, Qt::AlignCenter);

    setCentralWidget(tableView);

    tableModel->addStreamData("MU01");
    tableModel->addStreamData("MU02");
    tableModel->addStreamData("MU03");
    tableModel->addStreamData("MU02");

    tableView->resizeColumnsToContents();

    setWindowTitle(tr("discover"));
    setMinimumWidth(600);
}

MainWindow::~MainWindow()
{
}
