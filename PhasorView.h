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

#ifndef PHASORVIEW_H
#define PHASORVIEW_H

#include <QGraphicsView>

class PhasorView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit PhasorView(QObject *parent = 0);

protected:
    void scrollContentsBy(int, int)
    {
        // do nothing
    }

signals:
    
public slots:
    
};

#endif // PHASORVIEW_H
