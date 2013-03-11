#include "StatusWidget.h"
#include "ui_StatusWidget.h"
#include <QHostInfo>
#include <QNetworkConfigurationManager>
#include <QNetworkConfiguration>
#include <QNetworkSession>
#include <QList>
#include <QProcessEnvironment>

QString getUsername(){
    QString user = QProcessEnvironment::systemEnvironment().value("USER");
    if(user.isEmpty())
        user = QProcessEnvironment::systemEnvironment().value("USERNAME");
    return user;
}


StatusWidget::StatusWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatusWidget)
{
    ui->setupUi(this);

    QNetworkConfigurationManager mgr;
    QNetworkConfiguration nconfig = mgr.defaultConfiguration();
    QNetworkSession session ( nconfig );
    QNetworkInterface ninter = session.interface();

    QList<QNetworkAddressEntry> laddr = ninter.addressEntries();
    for ( QList<QNetworkAddressEntry> ::const_iterator it = laddr.begin(); it != laddr.end(); ++it )
    {
        ui->IPlistWidget->addItem(it->ip().toString());
    }
    ui->HostNamelineEdit->setText(QHostInfo::localHostName());
    ui->NickNamelineEdit->setText(getUsername());
}

StatusWidget::~StatusWidget()
{
    delete ui;
}
