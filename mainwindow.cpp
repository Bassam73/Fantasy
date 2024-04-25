#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logingui.h"
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
    close();
    MyProfileGui myprofileguiDialog;
    myprofileguiDialog.exec();
}

