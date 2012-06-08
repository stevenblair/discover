#include "phasorplotview.h"

PhasorPlotView::PhasorPlotView(QWidget *parent) : QAbstractItemView(parent)
{
}

QRect PhasorPlotView::visualRect(const QModelIndex &index) const
{
    return QRect();// QAbstractItemView::visualRect(index);
}

void PhasorPlotView::scrollTo(const QModelIndex &index, QAbstractItemView::ScrollHint hint)
{
}

QModelIndex PhasorPlotView::indexAt(const QPoint &point) const
{
    return QModelIndex();
}

void PhasorPlotView::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight)
{
    QAbstractItemView::dataChanged(topLeft, bottomRight);
}

void PhasorPlotView::rowsInserted(const QModelIndex &parent, int start, int end)
{
    QAbstractItemView::rowsInserted(parent, start, end);
}

void PhasorPlotView::rowsAboutToBeRemoved(const QModelIndex &parent, int start, int end)
{
}

bool PhasorPlotView::edit(const QModelIndex &index, QAbstractItemView::EditTrigger trigger, QEvent *event)
{
    return false;
}

QModelIndex PhasorPlotView::moveCursor(QAbstractItemView::CursorAction cursorAction, Qt::KeyboardModifiers modifiers)
{
    return QModelIndex();//QAbstractItemView::moveCursor(cursorAction, modifiers);
}

QRegion PhasorPlotView::visualRegionForSelection(const QItemSelection &selection) const
{
    return QRegion();//QAbstractItemView::visualRegionForSelection(selection);
}

void PhasorPlotView::setSelection(const QRect &, QItemSelectionModel::SelectionFlags command)
{
}

void PhasorPlotView::mousePressEvent(QMouseEvent *event)
{
}

bool PhasorPlotView::isIndexHidden(const QModelIndex &index) const
{
    return false;
}

int PhasorPlotView::verticalOffset() const
{
    return this->verticalOffset();
}

int PhasorPlotView::horizontalOffset() const
{
    return this->horizontalOffset();
}

void PhasorPlotView::scrollContentsBy(int dx, int dy)
{
}

void PhasorPlotView::resizeEvent(QResizeEvent *event)
{
}

void PhasorPlotView::paintEvent(QPaintEvent *event)
{
}

void PhasorPlotView::mouseReleaseEvent(QMouseEvent *event)
{
}

void PhasorPlotView::mouseMoveEvent(QMouseEvent *event)
{
}
