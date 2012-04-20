#include "pacientview.h"
#include <QPainter>
#include <QPaintEvent>

PacientView::PacientView(QWidget *parent) :
    QWidget(parent)
{
}

void PacientView::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);

    painter.fillRect(event->rect(), QBrush(Qt::blue));
    painter.drawText(10, 30, "Salut");

    painter.end();
}
