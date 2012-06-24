#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QTableView>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QGraphicsView>
#include <QTableWidget>
#include "ProxyItemView.h"
#include "streamtablemodel.h"
#include "commsthread.h"
#include "PhasorPlotTab.h"
#include "FrequencyTab.h"
#include "PowerTab.h"

extern CommsThread commsThread;

#define TABLE_VIEW_MINIMUM_HEIGHT   150

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

    // the model, and its views
    StreamTableModel *tableModel;
    QTableView *tableView;
    ProxyItemView *phasorPlotTabView;
    ProxyItemView *frequencyTabView;
    ProxyItemView *powerTabView;

    // the tab container, and the tabs
    QTabWidget *tabWidget;
    PhasorPlotTab *phasorPlotTab;
    FrequencyTab *frequencyTab;
    PowerTab *powerTab;
};

#endif // MAINWINDOW_H
