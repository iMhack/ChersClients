#include "settings.h"
#include "bac_a_sable.h"
#include "ui_settings.h"
#include <QDebug>
#include <QSettings>

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(okClick()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(noClick()));
    //A la construction, mise des anciens param dans les champs
    QSettings settings("options.ini", QSettings::IniFormat);
    ui->option1->setText(settings.value("DBfile").toString());
    ui->option2->setText(settings.value("DBname").toString());


}

Settings::~Settings()
{
    delete ui;
}
void Settings::okClick() //Quand on clic sur OK, on sauve dans options.ini les options
{
    qDebug() << "Settings::okClick() called";
    QSettings settings("options.ini", QSettings::IniFormat);
    settings.setValue("DBfile",ui->option1->text());
    settings.setValue("DBname", ui->option2->text());
    close();
}
void Settings::noClick()
{
    qDebug() << "Settings::noClick() called";
    close();
}

