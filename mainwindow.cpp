#include "mainwindow.h"
#include <QToolBar>
#include <QAction>
#include <QMenuBar>

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

    _widgetMenu = new QMenu("Window", this);
    menuBar()->addMenu(_widgetMenu);
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::addCentralWidget(CentralWidget *widget)
{
    _centralWidgetList << widget;

    _widgetMenu->addAction(widget->widgetName(), this, SLOT(actionChangeCentralWidget()));

    if (_centralWidgetList.size() == 1)
        changeCentralWidget(widget);
}

void MainWindow::actionUndo()
{
    // annule la dernère action dans la BDD
    CentralWidget *w = qobject_cast<CentralWidget *>(centralWidget());
    w->updateData();
}

void MainWindow::actionRedo()
{
    // annule la dernère annulation dans la BDD
    CentralWidget *w = qobject_cast<CentralWidget *>(centralWidget());
    w->updateData();
}

void MainWindow::actionChangeCentralWidget()
{
    QAction *action = qobject_cast<QAction *>(sender());

    if (action != 0) {
        int index = _widgetMenu->actions().indexOf(action);

        if (index != -1) {
            changeCentralWidget(_centralWidgetList.value(index, 0));
        }
    }
}

void MainWindow::changeCentralWidget(CentralWidget *widget)
{
    CentralWidget *old = qobject_cast<CentralWidget *>(centralWidget());

    if (old != 0) {
        removeToolBar(old->toolBar());
    }

    if (widget != 0) {
        if (widget->toolBar())
            addToolBar(widget->toolBar());
        setCentralWidget(widget);
    }
}
