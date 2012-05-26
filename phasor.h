#ifndef PHASOR_H
#define PHASOR_H

#include <QGraphicsScene>
#include "phasorline.h"
#include "streamtablemodel.h"

class PhasorScene : public QGraphicsScene
{
    Q_OBJECT
public:
    PhasorScene(StreamTableModel *tableModel, QObject *parent = 0);
public slots:
    void streamSelectionChanged(QString svID);

private:
    QGraphicsItem *phasorLine[3];
    StreamTableModel *tableModel;
};

#endif // PHASOR_H
