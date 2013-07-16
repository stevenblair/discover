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
 *
 * some code from: http://www.qtcentre.org/wiki/index.php?title=QGraphicsView:_Smooth_Panning_and_Zooming
 */

#include "PlotView.h"
#include "PlotScene.h"
#include "PhasorScene.h"

#include <QtGui>


PlotView::PlotView(QObject *parent)
{
    this->setMinimumWidth(PLOT_VIEW_WIDTH);
    this->setMinimumHeight(PLOT_VIEW_HEIGHT);
    this->setMaximumHeight(PLOT_VIEW_HEIGHT);
    this->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    this->setDragMode(QGraphicsView::ScrollHandDrag);
    this->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    /*QMatrix matrix;
    matrix.scale(7000.0, 0.05);
    this->setMatrix(matrix);*/
    //this->centerOn(0.0, 0.0);
}


/**
  * Sets the current centerpoint.  Also updates the scene's center point.
  * Unlike centerOn, which has no way of getting the floating point center
  * back, SetCenter() stores the center point.  It also handles the special
  * sidebar case.  This function will claim the centerPoint to sceneRec ie.
  * the centerPoint must be within the sceneRec.
  */
// Set the current centerpoint in the
void PlotView::SetCenter(const QPointF& centerPoint) {
    // Get the rectangle of the visible area in scene coords
    QRectF visibleArea = mapToScene(rect()).boundingRect();

    // Get the scene area
    QRectF sceneBounds = sceneRect();

    double boundX = visibleArea.width() / 2.0;
    double boundY = visibleArea.height() / 2.0;
    double boundWidth = sceneBounds.width() - 2.0 * boundX;
    double boundHeight = sceneBounds.height() - 2.0 * boundY;

    // The max boundary that the centerPoint can be to
    QRectF bounds(boundX, boundY, boundWidth, boundHeight);

    if (bounds.contains(centerPoint)) {
        // We are within the bounds
        CurrentCenterPoint = centerPoint;
    }
    else {
        // We need to clamp or use the center of the screen
        if (visibleArea.contains(sceneBounds)) {
            // Use the center of scene ie. we can see the whole scene
            CurrentCenterPoint = sceneBounds.center();
        }
        else {
            CurrentCenterPoint = centerPoint;

            // We need to clamp the center. The centerPoint is too large
            if (centerPoint.x() > bounds.x() + bounds.width()) {
                CurrentCenterPoint.setX(bounds.x() + bounds.width());
            }
            else if(centerPoint.x() < bounds.x()) {
                CurrentCenterPoint.setX(bounds.x());
            }

            if (centerPoint.y() > bounds.y() + bounds.height()) {
                CurrentCenterPoint.setY(bounds.y() + bounds.height());
            }
            else if(centerPoint.y() < bounds.y()) {
                CurrentCenterPoint.setY(bounds.y());
            }

        }
    }

    // Update the scrollbars
    centerOn(CurrentCenterPoint);
}

/**
  * Zoom the view in and out.
  */
void PlotView::wheelEvent(QWheelEvent* event) {

    // Get the position of the mouse before scaling, in scene coords
    QPointF pointBeforeScale(mapToScene(event->pos()));

    // Get the original screen centerpoint
    QPointF screenCenter = GetCenter(); //CurrentCenterPoint; //(visRect.center());

    // Scale the view ie. do the zoom
    double scaleFactor = 1.25; // How fast we zoom
    if (event->delta() > 0) {
        // Zoom in
        scale(scaleFactor, scaleFactor);
    }
    else {
        // Zooming out
        scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    }

    // Get the position after scaling, in scene coords
    QPointF pointAfterScale(mapToScene(event->pos()));

    // Get the offset of how the screen moved
    QPointF offset = pointBeforeScale - pointAfterScale;

    // Adjust to the new center for correct zooming
    QPointF newCenter = screenCenter + offset;
    SetCenter(newCenter);
}

void PlotView::resizeEvent(QResizeEvent *event)
{
    PlotScene *scene = (PlotScene *) this->scene();
    scene->setDrawnStatus(false);

    fitInView(scene->itemsBoundingRect(), Qt::IgnoreAspectRatio);
    QGraphicsView::resizeEvent(event);
}

void PlotView::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::RightButton ){
        PlotScene *scene = (PlotScene *) this->scene();
        scene->setDrawnStatus(false);

        fitInView(scene->itemsBoundingRect(), Qt::IgnoreAspectRatio);
    }
    QGraphicsView::mousePressEvent(event);
}
