#include "myprofilegui.h"
#include "ui_myprofilegui.h"

MyProfileGui::MyProfileGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyProfileGui)
{
    ui->setupUi(this);
}

MyProfileGui::~MyProfileGui()
{
    delete ui;
}

void MyProfileGui::on_commandLinkButton_clicked()
{
    close();
}
