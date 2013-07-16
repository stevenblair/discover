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

#include "TabViewWidget.h"

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
