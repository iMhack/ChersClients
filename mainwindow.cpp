#include "mainwindow.h"
#include <QToolBar>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QToolBar *toolbar = new QToolBar(this);
    QPixmap pix(":/images/undo.png");
    undoAction = toolbar->addAction(QIcon(pix),
                                    "undo", this, SLOT(actionUndo()));
    undoAction->setEnabled(false);
    redoAction = toolbar->addAction(QIcon(pix.transformed(QTransform::fromScale(-1, 1))),
                                    "redo", this, SLOT(actionRedo()));
    redoAction->setEnabled(false);
    addToolBar(toolbar);

    _pacientView = new QGraphicsView(this);
    _pacientScene = new PacientScene(this);
    _pacientView->setScene(_pacientScene);
    _pacientView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _pacientView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setCentralWidget(_pacientView);
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::actionUndo()
{
}

void MainWindow::actionRedo()
{
}
