#include "formpacientssheets.h"
#include "ui_formpacientssheets.h"

FormPacientsSheets::FormPacientsSheets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormPacientsSheets)
{
    ui->setupUi(this);

    _pacientScene = new PacientScene(this);
    ui->graphicsView->setScene(_pacientScene);

    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Date" << "Treatment" << "Payment mode");
}

FormPacientsSheets::~FormPacientsSheets()
{
    delete ui;
}
