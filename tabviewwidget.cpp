#include "tabviewwidget.h"

#include <QPalette>

TabViewWidget::TabViewWidget(QWidget *parent) : QWidget(parent)
{

}


void TabViewWidget::setSelectedRowIndex(QModelIndex &index)
{
    if (index.isValid()) {
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
}

void TabViewWidget::setModel(StreamTableModel *model)
{
    this->model = model;
}

//void TabViewWidget::setRow(StreamTableRow *row)
//{
//}
