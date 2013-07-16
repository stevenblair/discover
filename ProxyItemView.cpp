/**
 * discover - a real-time monitoring and analysis tool for IEC 61850-9-2LE Sampled Values
 *
 * Copyright (c) 2013 Steven Blair
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

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
    //qDebug() << "data changed, rows" << topLeft.row() << "to" << bottomRight.row();

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
    //qDebug() << "in rowsAboutToBeRemoved()" << start << end;

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
