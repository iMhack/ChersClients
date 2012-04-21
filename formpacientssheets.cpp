#include "formpacientssheets.h"
#include "ui_formpacientssheets.h"

FormPacientsSheets::FormPacientsSheets(QWidget *parent) :
    CentralWidget(parent),
    ui(new Ui::FormPacientsSheets)
{
    ui->setupUi(this);

    _pacientScene = new PacientScene(this);
    ui->graphicsView->setScene(_pacientScene);
}

FormPacientsSheets::~FormPacientsSheets()
{
    delete ui;
}

QToolBar *FormPacientsSheets::toolBar()
{
    return 0;
}

QString FormPacientsSheets::widgetName() const
{
    return "Pacients Interface";
}

void FormPacientsSheets::updateData()
{
}
