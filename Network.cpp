#include "Network.h"
#include <QStringList>
#include <QHostInfo>
#include <QNetworkConfigurationManager>
#include <QNetworkConfiguration>
#include <QNetworkSession>
#include <QList>

Network::Network(QObject *parent) :
    QObject(parent)
{
}

QString Network::getHostname(){
    return QHostInfo::localHostName();
}

QStringList Network::getIPAdresses(){
    QStringList list;
    QNetworkConfigurationManager mgr;
    QNetworkConfiguration nconfig = mgr.defaultConfiguration();
    QNetworkSession session ( nconfig );
    QNetworkInterface ninter = session.interface();

    QList<QNetworkAddressEntry> laddr = ninter.addressEntries();
    for ( QList<QNetworkAddressEntry> ::const_iterator it = laddr.begin(); it != laddr.end(); ++it )
    {
        list.append(it->ip().toString());
    }
    return list;
}
