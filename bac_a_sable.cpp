#include "bac_a_sable.h"
#include "ui_bac_a_sable.h"
#include "settings.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QTableView>
#include <QSqlRelationalTableModel>
#include <QSettings>


Bac_a_sable::Bac_a_sable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bac_a_sable)
{
    ui->setupUi(this);
    qDebug() << "bac a sable cree";
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(onACliqueSurOk()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(noClick()));


}

Bac_a_sable::~Bac_a_sable()
{
    delete ui;
}

void Bac_a_sable::onACliqueSurOk()
{
    qDebug() << "Bac_a_sable::onACliqueSurOk() called";
    //// Ouverture de la connexion à la database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "clients");
    db.setHostName("localhost");
    QSettings settings("options.ini", QSettings::IniFormat); // Partie de récup du settings du fichier de database
    db.setDatabaseName(settings.value("DBfile").toString()); // On choisi DBname du options.ini
    qDebug() << "DBfile : " << settings.value("DBfile").toString();
    qDebug() << "DBname : "<< settings.value("DBname").toString();
    db.setUserName("root"); // a modif pour release finale
    db.setPassword(""); // on le met dans un fichiers settings ?
    bool ok = db.open();

    //On rajoute les valeurs du formulaire dans la DB
    if(ok){
        qDebug() << "db.open true";
        QSqlQuery query(db);
        //Ajout des valeurs du formulaire dans la DB
        query.exec("CREATE TABLE "+(settings.value("DBname").toString())
                   +" (id INTEGER PRIMARY KEY, firstName VARCHAR, lastName VARCHAR, dateOfBirth VARCHAR, adress VARCHAR, sentBy VARCHAR, "
                   +"profess VARCHAR, telNumPriv VARCHAR, telNumPort VARCHAR, assurance VARCHAR, "
                   +"motifDeConsult VARCHAR, anamnSiege VARCHAR, anamnIrradiation VARCHAR, anamnQualite VARCHAR, anamnIntensite VARCHAR, "
                   +"anamnDebut VARCHAR, anamnDuree VARCHAR, anamnFrequence VARCHAR, allergies VARCHAR, "
                   +"habitudesTabac VARCHAR, habitudesMedic VARCHAR, habitudesPositionDeTravail VARCHAR, habitudesAlcool VARCHAR, "
                   +"habitudesNutrition VARCHAR, habitudesSport VARCHAR, antecedantsPersoTrauma VARCHAR, antecedentsPersoOperation VARCHAR, "
                   +"antecedentsFamiliaux VARCHAR, anameseSysteEtatGeneral VARCHAR, anameseSysteFatigue VARCHAR, anameseSysteTaille VARCHAR, "
                   +"anameseSystePoids VARCHAR, anameseSysteTemperature VARCHAR, anameseSysteDigestif VARCHAR, anameseSysteORL VARCHAR, "
                   +"anameseSystePulm VARCHAR, anameseSysteCardioVasc VARCHAR, anameseSysteUroGenital VARCHAR, anameseSysteEndocrinien VARCHAR, "
                   +"anameseSysteMusculoSqueletique VARCHAR, anameseSysteTete VARCHAR, anameseSysteVisionVertiges VARCHAR, "
                   +"examens VARCHAR, extraTitre VARCHAR, extraContenu VARCHAR ) ");
        query.prepare("INSERT INTO "+(settings.value("DBname").toString())+" (firstName, lastName, dateOfBirth, adress, sentBy, profess, "
                      +"telNumPriv, telNumPort, assurance, motifDeConsult, anamnSiege, anamnIrradiation, anamnQualite, "
                      +"anamnIntensite, anamnDebut, anamnDuree, anamnFrequence, allergies, habitudesTabac, habitudesMedic, "
                      +"habitudesPositionDeTravail, habitudesAlcool, habitudesNutrition, habitudesSport, antecedantsPersoTrauma, "
                      +"antecedentsPersoOperation, antecedentsFamiliaux, anameseSysteEtatGeneral, anameseSysteFatigue, "
                      +"anameseSysteTaille, anameseSystePoids, anameseSysteTemperature, anameseSysteDigestif, anameseSysteORL, "
                      +"anameseSystePulm, anameseSysteCardioVasc, anameseSysteUroGenital, anameseSysteEndocrinien, "
                      +"anameseSysteMusculoSqueletique, anameseSysteTete, anameseSysteVisionVertiges, "
                      +"examens, extraTitre, extraContenu ) "
                      +"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, "
                      +"?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
        query.addBindValue(ui->firstName->text());
        query.addBindValue(ui->lastName->text());
        query.addBindValue(ui->dateOfBirth->text());
        query.addBindValue(ui->adress->toPlainText());
        query.addBindValue(ui->sentBy->text());
        query.addBindValue(ui->profess->text());
        query.addBindValue(ui->telNumPriv->text());
        query.addBindValue(ui->telNumPort->text());
        query.addBindValue(ui->assurance->text());
        query.addBindValue(ui->motifDeConsult->toPlainText());
        query.addBindValue(ui->anamnSiege->text());
        query.addBindValue(ui->anamnIrradiation->text());
        query.addBindValue(ui->anamnQualite->text());
        query.addBindValue(ui->anamnIntensite->text());
        query.addBindValue(ui->anamnDebut->text());
        query.addBindValue(ui->anamnDuree->text());
        query.addBindValue(ui->anamnFrequence->text());
        query.addBindValue(ui->allergies->text());
        query.addBindValue(ui->habitudesTabac->text());
        query.addBindValue(ui->habitudesMedic->text());
        query.addBindValue(ui->habitudesPositionDeTravail->text());
        query.addBindValue(ui->habitudesAlcool->text());
        query.addBindValue(ui->habitudesNutrition->text());
        query.addBindValue(ui->habitudesSport->text());
        query.addBindValue(ui->antecedentsPersoTrauma->text());
        query.addBindValue(ui->antecedentsPersoOperation->text());
        query.addBindValue(ui->antecedentsFamiliaux->text());
        query.addBindValue(ui->anameseSysteEtatGeneral->text());
        query.addBindValue(ui->anameseSysteFatigue->text());
        query.addBindValue(ui->anameseSysteTaille->text());
        query.addBindValue(ui->anameseSystePoids->text());
        query.addBindValue(ui->anameseSysteTemperature->text());
        query.addBindValue(ui->anameseSysteDigestif->text());
        query.addBindValue(ui->anameseSysteORL->text());
        query.addBindValue(ui->anameseSystePulm->text());
        query.addBindValue(ui->anameseSysteCardioVasc->text());
        query.addBindValue(ui->anameseSysteUroGenital->text());
        query.addBindValue(ui->anameseSysteEndocrinien->text());
        query.addBindValue(ui->anameseSysteMuscSquelet->text());
        query.addBindValue(ui->anameseSysteTete->text());
        query.addBindValue(ui->anameseSysteVisionVertiges->text());
        query.addBindValue(ui->examens->toPlainText());
        query.addBindValue(ui->extraTitre->text());
        query.addBindValue(ui->extraContenu->toPlainText());

        qDebug() << "query exec " << query.exec();
    }
    else{
        qDebug() << "db.open false";
        QMessageBox::critical(0, "Error", db.lastError().text());
    }
    db.close();
    QSqlDatabase::removeDatabase("clients");
    close();
}
void Bac_a_sable::noClick()
{
    qDebug() << "Bac_a_sable::noClick() called";
    close();
}
