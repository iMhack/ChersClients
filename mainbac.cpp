#include <QApplication>
#include <settings.h>
#include <bac_a_sable.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    Settings s;
    Bac_a_sable w;

    w.show();
//    s.show();

    return app.exec();
}
