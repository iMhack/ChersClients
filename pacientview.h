#ifndef PACIENTVIEW_H
#define PACIENTVIEW_H

#include <QWidget>

class PacientView : public QWidget
{
    Q_OBJECT
public:
    explicit PacientView(QWidget *parent = 0);
    
protected:
    void paintEvent(QPaintEvent * event);

};

#endif // PACIENTVIEW_H
