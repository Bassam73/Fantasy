#include "loging.h"
#include "ui_loging.h"
#include "admin.h"
#include "myteam.h"
#include <QMessageBox>

loginG::loginG(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginG)
{
    ui->setupUi(this);
}

loginG::~loginG()
{
    delete ui;
}

void loginG::on_pushButton_clicked()
{
    QString name = ui->usernameLogin->text();
    QString password = ui->passwordLogin->text();
    string username= name.toStdString();
    string userPassword= password.toStdString();
    bool registerd= checkRegisteredUser(username,userPassword);

    MyTeam homePage ;
    if(registerd) homePage.exec();
    else {
        QMessageBox notFoundUser;

        notFoundUser.warning(this ,"login Failed" , "invalid Username password");


    }

}

bool loginG::checkRegisteredUser(string name ,string password){
    Admin usersList;

    for(long long i=0;i<usersList.usersList.size();i++){
        if(usersList.usersList[i].name==name&&
            usersList.usersList[i].password==password){
            return true;
        }
        return false;

    }

}
