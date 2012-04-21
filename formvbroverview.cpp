#include "formvbroverview.h"
#include "ui_formvbroverview.h"

FormVBROverview::FormVBROverview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormVBROverview)
{
    ui->setupUi(this);

    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Date of treatment" << "Date of mailing" << "Name of patient" << "Status");
}

FormVBROverview::~FormVBROverview()
{
    delete ui;
}
