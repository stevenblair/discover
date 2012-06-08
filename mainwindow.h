#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QTableView>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QGraphicsView>
#include <QTableWidget>
#include "phasorplotview.h"
#include "streamtablemodel.h"
//#include "phasorscene.h"
//#include "phasorview.h"
//#include "plotscene.h"
//#include "plotview.h"
#include "commsthread.h"
#include "phasorplotwidget.h"

extern CommsThread commsThread;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    StreamTableModel *getStreamTableModel();
    QTableView *getStreamTableView();

public slots:
    void addInterface(int value, QString name);

private:
    QLabel *networkInterfaceLabel;
    QComboBox *interfaceComboBox;

    StreamTableModel *tableModel;
    QTableView *tableView;
    PhasorPlotView *phasorPlotView;

    QTabWidget *tabWidget;
    PhasorPlotWidget *phasorPlotWidget;
    /*

    CurrentPhasorScene *currentPhasorScene;
    VoltagePhasorScene *voltagePhasorScene;
    CurrentPlotScene *currentPlotScene;
    VoltagePlotScene *voltagePlotScene;
    PhasorView *currentPhasorView;
    PhasorView *voltagePhasorView;
    PlotView *currentPlotView;
    PlotView *voltagePlotView;*/
};

#endif // MAINWINDOW_H
