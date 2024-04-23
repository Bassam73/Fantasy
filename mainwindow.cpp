#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    MyTeam myTeamDialog;
    myTeamDialog.exec();
}


void MainWindow::on_commandLinkButton_clicked()
{
    close();
}


void MainWindow::on_pushButton_2_clicked()
{
    Stats statsDialog;
    statsDialog.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    StandingsGui standingsguiDialog;
    standingsguiDialog.exec();
}


void MainWindow::on_pushButton_4_clicked()
{
    MyProfileGui myprofileguiDialog;
    myprofileguiDialog.exec();
}

