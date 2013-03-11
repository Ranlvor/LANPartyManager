#ifndef STATUSWIDGET_H
#define STATUSWIDGET_H

#include <QWidget>
#include "Network.h"
namespace Ui {
class StatusWidget;
}

class StatusWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit StatusWidget(QWidget *parent = 0);
    ~StatusWidget();
    void redraw();
    void setNetwork(Network * n);
    
private:
    Ui::StatusWidget *ui;
    Network * n;
};

#endif // STATUSWIDGET_H
