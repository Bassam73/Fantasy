#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user.h"
#include"transfergui.h"
#include <LoginUI.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    close();
    MyTeam myTeamDialog;
    myTeamDialog.exec();
}


void MainWindow::on_commandLinkButton_clicked()
{
    close();
    LoginUI loginPage;
    loginPage.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    close();
    Stats statsDialog;
    statsDialog.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    close();
    StandingsGui standingsguiDialog;
    standingsguiDialog.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    qDebug()<<"1";
    close();
    qDebug()<<"2";
    MyProfileGui myprofileguiDialog;
    myprofileguiDialog.exec();
}


void MainWindow::on_pushButton_5_clicked()
{
    close();
    TransferGui transferguiDialog;
    transferguiDialog.exec();
}

