#include "pacientscene.h"
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QMenu>
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
    _text->setHtml(text);
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
    TextEditor dialog(_text->toHtml());
    if (dialog.exec() == QDialog::Accepted)
        setText(dialog.html());
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
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
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
    addPixmap(QPixmap(":/images/corps.jpg"));

    _menu = new QMenu();
    _menu->addAction("New bubble...", this, SLOT(createBubble()));
}

PacientScene::~PacientScene()
{
    delete _menu;
}

void PacientScene::createBubble()
{
    Bubble *bubble = new Bubble();
    bubble->setText("Write text here...");
    bubble->setPos(_lastMousePressPosition);
    addItem(bubble);

    bubble->changeText();
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



#include <QVBoxLayout>
#include <QDialogButtonBox>

TextEditor::TextEditor(const QString &html, QWidget *parent) :
    QDialog(parent)
{
    _textEdit = new QTextEdit(this);
    _textEdit->setHtml(html);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Save | QDialogButtonBox::Cancel, Qt::Horizontal, this);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(_textEdit);
    layout->addWidget(buttonBox);

//    QAction *underline = new QAction(this);
//    underline->setShortcut(QKeySequence(QKeySequence::Underline));
//    connect(underline, SIGNAL(triggered(bool)), _textEdit, SLOT(setFontUnderline(bool)));
}

QString TextEditor::html() const
{
    return _textEdit->toHtml();
}
