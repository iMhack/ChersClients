#include "mainwindow.h"
#include <QToolBar>
#include <QAction>
#include <QMenuBar>

#include "formpacientssheets.h"
#include "formvbroverview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenu *mainmenu = new QMenu("Start", this);
    QAction *aOpen = mainmenu->addAction(QIcon(":/images/butters.png"), "Open customer record...", this, SLOT(actionOpenClient()));
    QAction *aNew = mainmenu->addAction(QIcon(":/images/butters2.png"), "New customer record...", this, SLOT(actionNewClient()));
    QAction *aVbr = mainmenu->addAction(QIcon(":/images/money.png"), "VBR Overview", this, SLOT(actionOpenVBROverview()));
    menuBar()->addMenu(mainmenu);

    QPixmap pix(":/images/undo.png");
    QToolBar *toolbar = new QToolBar(this);
    toolbar->addAction(aOpen);
    toolbar->addAction(aNew);
    toolbar->addAction(aVbr);
    undoAction = toolbar->addAction(QIcon(pix),
                                    "undo", this, SLOT(actionUndo()));
    undoAction->setEnabled(false);
    redoAction = toolbar->addAction(QIcon(pix.transformed(QTransform::fromScale(-1, 1))),
                                    "redo", this, SLOT(actionRedo()));
    redoAction->setEnabled(false);
    addToolBar(toolbar);



    _mdiArea = new QMdiArea(this);
    setCentralWidget(_mdiArea);
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::actionUndo()
{
    // annule la dernère action dans la BDD
}

void MainWindow::actionRedo()
{
    // annule la dernère annulation dans la BDD
}

void MainWindow::actionOpenClient()
{
    // ouvre la liste des pacients

    FormPacientsSheets *clientSheet = new FormPacientsSheets(this);
    clientSheet->setAttribute(Qt::WA_DeleteOnClose);
    _mdiArea->addSubWindow(clientSheet);
    clientSheet->show();
}

void MainWindow::actionNewClient()
{
    FormPacientsSheets *clientSheet = new FormPacientsSheets(this);
    clientSheet->setAttribute(Qt::WA_DeleteOnClose);
    _mdiArea->addSubWindow(clientSheet);
    clientSheet->show();
}

void MainWindow::actionOpenVBROverview()
{
    FormVBROverview *vbr = new FormVBROverview(this);
    vbr->setAttribute(Qt::WA_DeleteOnClose);
    _mdiArea->addSubWindow(vbr);
    vbr->show();
}
