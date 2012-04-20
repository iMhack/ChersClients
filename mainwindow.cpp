#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _pacientView = new QGraphicsView(this);
    _pacientScene = new PacientScene(this);
    _pacientView->setScene(_pacientScene);

    setCentralWidget(_pacientView);
}

MainWindow::~MainWindow()
{
    
}
