#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>

class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = 0);
    QString getHostname();
    QStringList getIPAdresses();
    
signals:
    
public slots:
    
};

#endif // NETWORK_H
