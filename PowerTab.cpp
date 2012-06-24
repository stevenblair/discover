
#include <QHeaderView>
#include "PowerTab.h"

PowerTab::PowerTab(QWidget *parent) : TabViewWidget(parent)
{
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);

    treeModel = new PowerTreeModel(this);

    tableView = new QTableView;
    tableView->setModel(treeModel);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->horizontalHeader()->setHighlightSections(false);
    tableView->verticalHeader()->hide();
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    verticalLayout->addWidget(tableView);
}

void PowerTab::update()
{
    this->treeModel->streamTableModelSelectionChanged(this->model, &this->index);
}

void PowerTab::removeView()
{
    qDebug() << "PowerTab::removeView()" << this->treeModel->rowCount();
    this->treeModel->removeRows(0, this->treeModel->rowCount());
}
