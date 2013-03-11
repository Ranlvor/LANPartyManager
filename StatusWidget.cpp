#include "StatusWidget.h"
#include "ui_StatusWidget.h"
#include <QProcessEnvironment>

QString getUsername(){
    QString user = QProcessEnvironment::systemEnvironment().value("USER");
    if(user.isEmpty())
        user = QProcessEnvironment::systemEnvironment().value("USERNAME");
    return user;
}


StatusWidget::StatusWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatusWidget), n(0)
{
    ui->setupUi(this);
    redraw();
}

StatusWidget::~StatusWidget()
{
    delete ui;
}

void StatusWidget::redraw(){
    if(n != 0) {
        QStringList ips = n->getIPAdresses();
        foreach (QString ip, ips) {
            ui->IPlistWidget->addItem(ip);
        }

        ui->HostNamelineEdit->setText(n->getHostname());
    }


    ui->NickNamelineEdit->setText(getUsername());
}

void StatusWidget::setNetwork(Network * n){
    this->n = n;
    redraw();
}
