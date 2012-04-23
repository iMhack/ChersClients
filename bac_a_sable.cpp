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

#include <QApplication>
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Bac_a_sable w;
    QSettings settings("../../../mesoptions.ini", QSettings::IniFormat);
    settings.setValue("Identite/NOM","");
    settings.setValue("Identite/Prénom","");
    settings.setValue("Identite/Date de naissance","");
    settings.setValue("Identite/Adresse","");
    settings.setValue("Identite/Envoyé par","");
    settings.setValue("Identite/Profession","");
    settings.setValue("Identite/Tel privé","");
    settings.setValue("Identite/Portable","");
    settings.setValue("Identite/Assurance","");
    settings.setValue("Identite/_","");
    settings.setValue("Anamnèse/Motif de consultation","");
    settings.setValue("Anamnèse/Siège","");
    settings.setValue("Anamnèse/Irradiation","");
    settings.setValue("Anamnèse/Qualité","");
    settings.setValue("Anamnèse/Intensité","");
    settings.setValue("Anamnèse/ChronologieDébut","");
    settings.setValue("Anamnèse/ChronologieDurée","");
    settings.setValue("Anamnèse/ChronologieFréquence","");
    settings.setValue("Anamnèse/Allérgies","");
    settings.setValue("Anamnèse/Tabac","");
    settings.setValue("Anamnèse/Alcool","");

    w.show();


    return app.exec();
}
