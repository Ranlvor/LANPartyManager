#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <QApplication>

MainWindow::MainWindow(Network *n, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusWidget->setNetwork(n);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    qApp->quit();
}
