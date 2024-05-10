#include "forgetpasswordgui.h"
#include "ui_forgetpasswordgui.h"
using namespace std;
#include <MainWindow.h>
#include <User.h>
#include <qmessagebox.h>
#include <string>

forgetPasswordgui::forgetPasswordgui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::forgetPasswordgui)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

}

forgetPasswordgui::~forgetPasswordgui()
{
    delete ui;
}

void forgetPasswordgui::on_pushButton_clicked()
{
    string username = ui->lineEdit->text().toStdString();
    string password = ui->lineEdit_2->text().toStdString();
    string rePassword =ui->lineEdit_3->text().toStdString();
    int x=-1;
    QMessageBox forgetPasswordError;

        User forgetPass;
        x=forgetPass.forgetPassword(username,password,rePassword);

    if(x==1){
        forgetPasswordError.warning(this,"","Wrong username");
    }
    else if(x==2){
        forgetPasswordError.warning(this,"","Invalid password");
    }
    else if(x==3){
       forgetPasswordError.warning(this,"","please re enter your passowrd");
    }
    else if(x==4){
        MainWindow* mainwindowDialog = new MainWindow();

            close();
            mainwindowDialog->show();

    }
}

