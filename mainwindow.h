#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QMenu>
#include "centralwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addCentralWidget(CentralWidget *widget);

private slots:
    void actionUndo();
    void actionRedo();
    void actionChangeCentralWidget();

private:
    void changeCentralWidget(CentralWidget *widget);

    QAction *undoAction;
    QAction *redoAction;

    QList<CentralWidget *> _centralWidgetList;
    QMenu *_widgetMenu;
};

#endif // MAINWINDOW_H
