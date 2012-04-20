#ifndef PACIENTSCENE_H
#define PACIENTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsObject>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>

class Bubble : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Bubble(QGraphicsItem *parent = 0);
    ~Bubble();
    void setText(const QString &text);
    QRectF boundingRect() const;

public slots:
    void changeText();
    void removeBubble();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    void updateLine();

    QGraphicsRectItem *_rectangle;
    QGraphicsTextItem *_text;
    QGraphicsLineItem *_line;

    QMenu *_menu;
};

class PacientScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PacientScene(QObject *parent = 0);
    ~PacientScene();

public slots:
    void createBubble();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QPointF _lastMousePressPosition;
    QMenu *_menu;
};

#endif // PACIENTSCENE_H
