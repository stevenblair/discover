#ifndef PHASORVIEW_H
#define PHASORVIEW_H

#include <QGraphicsView>

#define PHASOR_VIEW_MAX_PHASOR_SIZE 100
#define PHASOR_VIEW_MAX_SIZE        PHASOR_VIEW_MAX_PHASOR_SIZE + 5     // defines max distance from centre in any direction
#define PHASOR_VIEW_WIDTH           (2 * PHASOR_VIEW_MAX_SIZE)

class PhasorView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit PhasorView(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // PHASORVIEW_H
