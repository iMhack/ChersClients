#ifndef FORMPACIENTSSHEETS_H
#define FORMPACIENTSSHEETS_H

#include "pacientscene.h"

namespace Ui {
class FormPacientsSheets;
}

class FormPacientsSheets : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormPacientsSheets(QWidget *parent = 0);
    ~FormPacientsSheets();
    
private:
    Ui::FormPacientsSheets *ui;

    PacientScene *_pacientScene;
};

#endif // FORMPACIENTSSHEETS_H
