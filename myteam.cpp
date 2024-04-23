#include "myteam.h"
#include "ui_myteam.h"
MyTeam::MyTeam(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyTeam)
{
    ui->setupUi(this);
}

MyTeam::~MyTeam()
{
    delete ui;
}

void MyTeam::on_commandLinkButton_clicked()
{
    close();
}
