#include "myprofilegui.h"
#include "ui_myprofilegui.h"
#include "mainwindow.h"
#include "admin.h"
MyProfileGui::MyProfileGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyProfileGui)
{
    ui->setupUi(this);
    ui->label_3->setText(User::currentUserData.name.data());
    ui->label_4->setText(User::currentUserData.league.data());
    ui->label_5->setText("99999");

}


MyProfileGui::~MyProfileGui()
{
    delete ui;
}


void MyProfileGui::on_commandLinkButton_clicked()
{
    close();
    MainWindow* mainwindowDialog = new MainWindow();
    mainwindowDialog->show();
}

