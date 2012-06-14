#include "ProxyItemView.h"
#include <QDebug>


ProxyItemView::ProxyItemView(TabViewWidget *widget, QAbstractItemModel *model, QWidget *parent) : QAbstractItemView(parent)
{
    QAbstractItemView::setModel(model);
    this->widget = widget;
    this->widget->setModel((StreamTableModel *) this->model());
}

QRect ProxyItemView::visualRect(const QModelIndex &index) const
{
    return QRect();// QAbstractItemView::visualRect(index);
}

void ProxyItemView::scrollTo(const QModelIndex &index, QAbstractItemView::ScrollHint hint)
{
}

QModelIndex ProxyItemView::indexAt(const QPoint &point) const
{
    return QModelIndex();
}

void ProxyItemView::setModel(QAbstractItemModel *model)
{
    QAbstractItemView::setModel(model);

    this->widget->setModel((StreamTableModel *) model);
}

void ProxyItemView::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight)
{
    QAbstractItemView::dataChanged(topLeft, bottomRight);
    qDebug() << "data changed, rows" << topLeft.row() << "to" << bottomRight.row();

    if (this->widget->getIndex()->isValid()) {
        int row = this->widget->getIndex()->row();

        if (row >= topLeft.row() && row <= bottomRight.row()) {
            this->widget->update();
            //qDebug() << "data changed for row" << row;
        }
    }
}

void ProxyItemView::rowsInserted(const QModelIndex &parent, int start, int end)
{
    QAbstractItemView::rowsInserted(parent, start, end);
}

void ProxyItemView::rowsAboutToBeRemoved(const QModelIndex &parent, int start, int end)
{
    qDebug() << "in rowsAboutToBeRemoved()" << start << end;

    this->widget->removeView();
}

bool ProxyItemView::edit(const QModelIndex &index, QAbstractItemView::EditTrigger trigger, QEvent *event)
{
    return false;
}

QModelIndex ProxyItemView::moveCursor(QAbstractItemView::CursorAction cursorAction, Qt::KeyboardModifiers modifiers)
{
    return QModelIndex();//QAbstractItemView::moveCursor(cursorAction, modifiers);
}

QRegion ProxyItemView::visualRegionForSelection(const QItemSelection &selection) const
{
    return QRegion();//QAbstractItemView::visualRegionForSelection(selection);
}

void ProxyItemView::setSelection(const QRect &, QItemSelectionModel::SelectionFlags command)
{
    //qDebug() << "in setSelection()";
}

void ProxyItemView::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    //qDebug() << "in selectionChanged()" << selected.size() << selected.indexes().size();

    if (!selected.isEmpty() && selected.size() == 1) {
        this->widget->setSelectedRowIndex(selected.indexes().first());
    }
}

void ProxyItemView::mousePressEvent(QMouseEvent *event)
{
}

bool ProxyItemView::isIndexHidden(const QModelIndex &index) const
{
    return false;
}

int ProxyItemView::verticalOffset() const
{
    return this->verticalOffset();
}

int ProxyItemView::horizontalOffset() const
{
    return this->horizontalOffset();
}

void ProxyItemView::scrollContentsBy(int dx, int dy)
{
}

void ProxyItemView::resizeEvent(QResizeEvent *event)
{
}

void ProxyItemView::paintEvent(QPaintEvent *event)
{
}

void ProxyItemView::mouseReleaseEvent(QMouseEvent *event)
{
}

void ProxyItemView::mouseMoveEvent(QMouseEvent *event)
{
}
