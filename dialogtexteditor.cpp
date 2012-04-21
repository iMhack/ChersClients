#include "dialogtexteditor.h"
#include "ui_dialogtexteditor.h"

DialogTextEditor::DialogTextEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTextEditor)
{
    ui->setupUi(this);
    initFont(QFont());
    _textDocument = ui->textEdit->document();
}

DialogTextEditor::DialogTextEditor(const QString &html, const QFont &font, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTextEditor)
{
    ui->setupUi(this);
    ui->textEdit->setHtml(html);
    initFont(font);
    _textDocument = ui->textEdit->document();
}

DialogTextEditor::~DialogTextEditor()
{
    delete ui;
}

QString DialogTextEditor::html() const
{
    return ui->textEdit->toHtml();
}

void DialogTextEditor::initFont(const QFont &font)
{
    ui->bold->setChecked(font.bold());
    ui->italic->setChecked(font.italic());
    ui->font->setFont(font);
    ui->size->setValue(font.pointSize());
}

