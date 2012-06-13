#include "FrequencyTab.h"

FrequencyTab::FrequencyTab(QWidget *parent) : TabViewWidget(parent)
{
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);

    frequencyScene = new FrequencyScene();
    frequencyView = new QGraphicsView(this);
    frequencyView->setScene(frequencyScene);

    frequencyView->setRenderHint(QPainter::Antialiasing);    // TODO: move into subclass?

    verticalLayout->addWidget(frequencyView, 0, 0);

    this->views.append(frequencyView);
}

void FrequencyTab::update()
{
    frequencyScene->streamTableModelSelectionChanged(this->model, &this->index);
}

void FrequencyTab::removeView()
{
}
