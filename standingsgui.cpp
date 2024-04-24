#include "standingsgui.h"
#include "ui_standingsgui.h"
#include "mainwindow.h"
StandingsGui::StandingsGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StandingsGui)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

}

StandingsGui::~StandingsGui()
{
    delete ui;
}

void StandingsGui::on_commandLinkButton_clicked()
{
    close();
    MainWindow* mainwindowDialog = new MainWindow();
    mainwindowDialog->show();
}

