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

private:
    QGraphicsView *_pacientView;
    PacientScene *_pacientScene;
};

#endif // MAINWINDOW_H
