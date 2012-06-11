#include "tabviewwidget.h"

#include <QPalette>

TabViewWidget::TabViewWidget(QWidget *parent) : QWidget(parent)
{
    //this->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    QPalette p(this->palette());
    p.setColor(QPalette::Background, Qt::red);
    this->setAutoFillBackground(true);
    this->setPalette(p);
}


void TabViewWidget::setSelectedRowIndex(QModelIndex &index)
{
    this->index = QPersistentModelIndex(index);

    if (this->index.isValid()) {
        this->update();

//        QListIterator<QGraphicsView*> i (views);

//        while (i.hasNext()) {
//            const QGraphicsView *view = i.next();
//            view->scene()->update();        // TODO: may need to override this (or other function or slot) in subclass?
//        }
    }
}

void TabViewWidget::setModel(StreamTableModel *model)
{
    this->model = model;
}

//void TabViewWidget::setRow(StreamTableRow *row)
//{
//}
