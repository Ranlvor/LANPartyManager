#include <QApplication>
#include "MainWindow.hpp"
#include "Network.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Network * n = new Network;
    MainWindow w(n);
    w.show();
    
    return a.exec();
}
