#ifndef PHASOR_H
#define PHASOR_H

#include <QGraphicsScene>
#include "phasorline.h"

class Phasor : public QGraphicsScene
{
public:
    Phasor();

private:
    QGraphicsItem *phasorLine[3];
};

#endif // PHASOR_H
