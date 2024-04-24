#include "registergui.h"
#include "ui_registergui.h"
#include "user.h"
#include "mainwindow.h"
#include "myteam.h"
#include <QMessageBox>
#include "loginui.h"

RegisterGui::RegisterGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterGui)
{
    ui->setupUi(this);
}

RegisterGui::~RegisterGui()
{
    delete ui;

}

void RegisterGui::on_pushButton_clicked()
{

    QString name = ui->usernameQedit->text();
    QString password = ui->passwordQedit->text();
    QString repassword = ui->repasswordQedit->text();
    QString league = ui->leagueBox->currentText();

    if(password != repassword){
        QMessageBox::about(this , "Register Failed", "Please confirm the password");
    }
    else{
        string username= name.toStdString();
        string userPassword= password.toStdString();
        string userLeague= league.toStdString();

       User * userPtr= new User(username , userPassword , userLeague);

        bool check = userPtr->registerUser();



       MainWindow* mainwindowDialog = new MainWindow();
        if(check){
           close();
           mainwindowDialog->show();
        }
        else {
            QMessageBox registerFailed;
            // registerFailed.setStyleSheet("QLabel{min-width: 700px;}");

            registerFailed.about(this ,"Register Failed" , "Username is already used or invalid password");


        }

        delete userPtr;
    }



}


void RegisterGui::on_pushButton_2_clicked()
{
    LoginUI loginPage;
    loginPage.exec();
}

