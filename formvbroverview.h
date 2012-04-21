#ifndef FORMVBROVERVIEW_H
#define FORMVBROVERVIEW_H

#include <QWidget>

namespace Ui {
class FormVBROverview;
}

class FormVBROverview : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormVBROverview(QWidget *parent = 0);
    ~FormVBROverview();
    
private:
    Ui::FormVBROverview *ui;
};

#endif // FORMVBROVERVIEW_H
