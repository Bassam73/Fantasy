#include "myteam.h"
#include "ui_myteam.h"
#include "mainwindow.h"
MyTeam::MyTeam(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyTeam)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
}

MyTeam::~MyTeam()
{
    delete ui;
}

void MyTeam::on_commandLinkButton_clicked()
{
    close();
    MainWindow* mainwindowDialog = new MainWindow();
    mainwindowDialog->show();
}
