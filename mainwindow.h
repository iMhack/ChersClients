#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QMenu>
#include <QMdiArea>
#include <QMdiSubWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void actionUndo();
    void actionRedo();
    void actionOpenClient();
    void actionNewClient();
    void actionOpenVBROverview();

private:
    QAction *undoAction;
    QAction *redoAction;

    QMdiArea *_mdiArea;
};

#endif // MAINWINDOW_H
