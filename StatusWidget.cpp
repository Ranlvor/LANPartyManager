#include "StatusWidget.h"
#include "ui_StatusWidget.h"
#include <QHostInfo>
#include <QNetworkConfigurationManager>
#include <QNetworkConfiguration>
#include <QNetworkSession>
#include <QList>


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
}

StatusWidget::~StatusWidget()
{
    delete ui;
}
