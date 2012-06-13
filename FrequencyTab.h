#ifndef FREQUENCYTAB_H
#define FREQUENCYTAB_H

#include <QWidget>
#include <QVBoxLayout>
#include "tabviewwidget.h"
#include "FrequencyScene.h"

class FrequencyTab : public TabViewWidget
{
    Q_OBJECT
public:
    explicit FrequencyTab(QWidget *parent = 0);
    void update();
    void removeView();

signals:

public slots:

private:
    QList<QGraphicsView*> views;

    FrequencyScene *frequencyScene;
    QGraphicsView *frequencyView;
};

#endif // FREQUENCYTAB_H
