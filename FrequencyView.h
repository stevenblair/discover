#ifndef FREQUENCYVIEW_H
#define FREQUENCYVIEW_H

#include <QGraphicsView>

class FrequencyView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit FrequencyView(QObject *parent = 0);

signals:
    
public slots:

protected:
    virtual void resizeEvent(QResizeEvent* event);
};

#endif // FREQUENCYVIEW_H
