#ifndef DIALOGTEXTEDITOR_H
#define DIALOGTEXTEDITOR_H

#include <QDialog>
#include <QTextDocument>

namespace Ui {
class DialogTextEditor;
}

class DialogTextEditor : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogTextEditor(QWidget *parent = 0);
    explicit DialogTextEditor(const QString &html, const QFont &font = QFont(), QWidget *parent = 0);
    ~DialogTextEditor();

    QString html() const;
    
private:
    void initFont(const QFont &font);
    Ui::DialogTextEditor *ui;

    QTextDocument *_textDocument;
};

#endif // DIALOGTEXTEDITOR_H
