#include "bac_a_sable.h"
#include "ui_bac_a_sable.h"

Bac_a_sable::Bac_a_sable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bac_a_sable)
{
    ui->setupUi(this);
}

Bac_a_sable::~Bac_a_sable()
{
    delete ui;
}
