#ifndef FORMPACIENTSSHEETS_H
#define FORMPACIENTSSHEETS_H

#include "centralwidget.h"
#include "pacientscene.h"

namespace Ui {
class FormPacientsSheets;
}

class FormPacientsSheets : public CentralWidget
{
    Q_OBJECT
    
public:
    explicit FormPacientsSheets(QWidget *parent = 0);
    ~FormPacientsSheets();
    QToolBar *toolBar();
    QString widgetName() const;
    
public slots:
    void updateData();

private:
    Ui::FormPacientsSheets *ui;

    PacientScene *_pacientScene;
};

#endif // FORMPACIENTSSHEETS_H
