#include "registergui.h"
#include "ui_registergui.h"
#include "user.h"
#include "mainwindow.h"
#include "myteam.h"
#include <QMessageBox>
#include "loginui.h"
#include"usersdata.h"
#include "admin.h"

Admin loadData;

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

        Admin generateId;
        int id = 9/*generateId.usersList[generateId.usersList.size()-1].id + 1*/;
        string username= name.toStdString();
        string userPassword= password.toStdString();
        string userLeague= league.toStdString();
        qDebug() << "here";

        User * userPtr= new User(id , username , userPassword , userLeague);

        bool check = userPtr->registerUser();



        MainWindow* mainwindowDialog = new MainWindow();
        if(check){
            close();

            mainwindowDialog->show();
            UsersData da;
            da.storeData();


        }
        else {
            QMessageBox registerFailed;
            // registerFailed.setStyleSheet("QLabel{min-width: 700px;}");

            registerFailed.about(this ,"Register Failed" , "Username is already used or invalid password");


        }
    }

}


void RegisterGui::on_pushButton_2_clicked()
{
    close();
    LoginUI loginPage;
    loginPage.exec();
}

