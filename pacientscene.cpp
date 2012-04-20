#include "pacientscene.h"
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QMenu>
#include <QInputDialog>
#include <QDebug>

Bubble::Bubble(QGraphicsItem *parent) :
    QGraphicsObject(parent)
{
    _menu = new QMenu();
    _menu->addAction("Modify text...", this, SLOT(changeText()));
    _menu->addAction("Remove bubble", this, SLOT(removeBubble()));

    _line = new QGraphicsLineItem(this);
    _line->setPen(QPen(QBrush(Qt::darkBlue), 2.0, Qt::DashLine, Qt::RoundCap));

    _rectangle = new QGraphicsRectItem(this);
    _rectangle->setPen(QPen(QBrush(Qt::blue), 2.0, Qt::DashLine, Qt::RoundCap));

    _text = new QGraphicsTextItem(this);
    _text->setDefaultTextColor(Qt::red);
}

Bubble::~Bubble()
{
    delete _menu;
}

void Bubble::setText(const QString &text)
{
    _text->setPlainText(text);
    QRectF rect = _text->boundingRect();
    QPointF center = _rectangle->pos();

    _text->setPos(center.x() - rect.width() / 2.0, center.y() - rect.height() / 2.0);

    rect.setWidth(rect.width() * 1.1);
    rect.setHeight(rect.height() * 1.1);
    rect.moveCenter(QPointF(0, 0));
    _rectangle->setRect(rect);

    updateLine();
}

QRectF Bubble::boundingRect() const
{
    QRectF rect = _rectangle->boundingRect();
    rect.moveCenter(_rectangle->pos());
    return rect;
}

void Bubble::changeText()
{
    bool ok;
    QString newtext = QInputDialog::getText(0, "Modify bubble", "Enter the text here", QLineEdit::Normal, _text->toPlainText(), &ok);

    if (ok) {
        setText(newtext);
    }
}

void Bubble::removeBubble()
{
    deleteLater();
}

void Bubble::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    event->accept();

    if ((event->buttons() & Qt::RightButton) == Qt::RightButton) {
        _menu->move(event->screenPos());
        _menu->show();
    }
}

void Bubble::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) == Qt::LeftButton) {
        QPointF delta = event->scenePos() - event->lastScenePos();
        _rectangle->setPos(_rectangle->pos() + delta);
        _text->setPos(_text->pos() + delta);

        updateLine();
    }
}

void Bubble::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}

void Bubble::updateLine()
{
    QRectF r = _rectangle->rect();
    QPointF p((_rectangle->pos().x() < 0.0 ? 0.5:-0.5) * r.width(),
              (_rectangle->pos().y() < 0.0 ? 0.5:-0.5) * r.height());
    _line->setLine(QLineF(QPointF(0, 0), _rectangle->pos() + p));
}

PacientScene::PacientScene(QObject *parent) :
    QGraphicsScene(parent)
{
    _menu = new QMenu();
    _menu->addAction("New bubble...", this, SLOT(createBubble()));
}

PacientScene::~PacientScene()
{
    delete _menu;
}

void PacientScene::createBubble()
{
//    QMenu *sender = qobject_cast<QMenu *>(sender());

    Bubble *bubble = new Bubble();
    bubble->setText("Write text here...");
    bubble->setPos(_lastMousePressPosition);
    addItem(bubble);
}

void PacientScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);

    if (!event->isAccepted() && (event->buttons() & Qt::RightButton) == Qt::RightButton) {
        event->accept();

        _menu->move(event->screenPos());
        _menu->show();

        _lastMousePressPosition = event->scenePos();
    }
}
