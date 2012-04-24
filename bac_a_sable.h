#ifndef BAC_A_SABLE_H
#define BAC_A_SABLE_H

#include <QWidget>
#include <QTableView>
#include <QSqlRelationalTableModel>

namespace Ui {
class Bac_a_sable;
}

class Bac_a_sable : public QWidget
{
    Q_OBJECT
    
public:
    explicit Bac_a_sable(QWidget *parent = 0);
    ~Bac_a_sable();



    
private slots:
    void onACliqueSurOk();

private:
    Ui::Bac_a_sable *ui;

};

#endif // BAC_A_SABLE_H
