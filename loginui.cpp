#include "loginui.h"
#include "ui_loginui.h"
#include "admin.h"
#include "myteam.h"
#include "user.h"
#include <QMessageBox>
#include <forgetPasswordgui.h>
#include "mainwindow.h"
#include "adminhomegui.h"

LoginUI::LoginUI(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginUI)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

}

LoginUI::~LoginUI()
{
    delete ui;
}

void LoginUI::on_pushButton_clicked()
{
    QString name = ui->usernameLogin->text();
    QString password = ui->passwordLogin->text();
    string username = name.toStdString();
    string userPassword = password.toStdString();
    AdminHomeGui * a = new AdminHomeGui;
    if(username == "admin" && userPassword == "admin"){
        close();
        a->show();
    }
    else{
        User * userLogin = new User();

        bool registerd = userLogin->checkRegisteredUser(username,userPassword);
        MainWindow* mainwindowDialog = new MainWindow();
        if(registerd){
            close();
            mainwindowDialog->show();
        }
        else {
            QMessageBox notFoundUser;

            notFoundUser.warning(this ,"login Failed" , "invalid Username password");


        }


        delete userLogin;
    }


}

void LoginUI::on_commandLinkButton_clicked()
{
    close();
    forgetPasswordgui* foretPassowrdWidget=new forgetPasswordgui;
    foretPassowrdWidget->show();
}
