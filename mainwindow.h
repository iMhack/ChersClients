#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QGraphicsView>
#include "pacientscene.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void actionUndo();
    void actionRedo();

private:
    QGraphicsView *_pacientView;
    PacientScene *_pacientScene;

    QAction *undoAction;
    QAction *redoAction;
};

#endif // MAINWINDOW_H
