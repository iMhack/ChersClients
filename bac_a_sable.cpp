#include "bac_a_sable.h"
#include "ui_bac_a_sable.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QTableView>
#include <QSqlRelationalTableModel>


Bac_a_sable::Bac_a_sable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bac_a_sable)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(onACliqueSurOk()));
}

Bac_a_sable::~Bac_a_sable()
{
    delete ui;
}

void Bac_a_sable::onACliqueSurOk()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "clients");
    db.setHostName("localhost");
    db.setDatabaseName("client.db");
    db.setUserName("root"); // a modif pour release finale
    db.setPassword(""); // on le met dans un fichiers settings ?
    bool ok = db.open();


    if(ok){
        qDebug() << "db.open ok";
        QSqlQuery query(db);
        query.exec("CREATE TABLE client (id INT, forename VARCHAR, surname VARCHAR, etc VARCHAR)");
        query.prepare("INSERT INTO client (id, forename, surname, etc) "
                      "VALUES (:id, :forename, :surname, :etc)");
        query.bindValue(":id", 1011);
        query.bindValue(":forename", ui->firstName->text());
        query.bindValue(":surname", ui->lastName->text());
        query.bindValue(":etc", ui->allergies->text());
        qDebug() << "query exec :" << query.exec();
    }
    else{
        qDebug() << "db.open ERROR";
        QMessageBox::critical(0, "Error", db.lastError().text());
    }
    db.close();
    QSqlDatabase::removeDatabase("clients");
    close();
}

#include <QApplication>
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Bac_a_sable w;

    QSettings settings("mesoptions.ini", QSettings::IniFormat);
    settings.setValue("database/name","client");

    w.show();

    return app.exec();
}
