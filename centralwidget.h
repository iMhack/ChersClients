#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include <QToolBar>

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget *parent = 0); // donner un pointeur vers la base de donnée
    virtual QToolBar *toolBar() = 0;
    virtual QString widgetName() const = 0;
    
signals:
    
public slots:
    virtual void updateData() = 0; // si le mainwindow change les données dans la base de données
    
};

#endif // CENTRALWIDGET_H
