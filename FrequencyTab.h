#ifndef FREQUENCYTAB_H
#define FREQUENCYTAB_H

#include <QWidget>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QSignalMapper>
#include "tabviewwidget.h"
#include "FrequencyScene.h"

class FrequencyTab : public TabViewWidget
{
    Q_OBJECT
public:
    explicit FrequencyTab(QWidget *parent = 0);
    void update();
    void removeView();

    static const QString checkBoxLabels[8];

signals:
    void redrawFrequencyScene();
    void checkBoxToggled(int id);

public slots:
    void setActiveWavefrom(int id);

private:
    QList<QGraphicsView*> views;

    FrequencyScene *frequencyScene;
    QGraphicsView *frequencyView;

    QCheckBox *activeWaveformCheckBox[8];
    QSignalMapper *checkBoxMapper;
};

#endif // FREQUENCYTAB_H
