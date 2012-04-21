#include <QtGui/QApplication>
#include "mainwindow.h"

#include "formpacientssheets.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;

    FormPacientsSheets p(&w);
    w.addCentralWidget(&p);

    w.show();

    
    return a.exec();
}
