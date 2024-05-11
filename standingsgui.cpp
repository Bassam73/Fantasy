#include "standingsgui.h"
#include "ui_standingsgui.h"
#include "mainwindow.h"
#include"user.h"

#include <qmessagebox.h>
StandingsGui::StandingsGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StandingsGui)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    User user;
    ui->textBrowser->setText(user.standings());
    ui->textBrowser->selectAll();
    ui->textBrowser->setAlignment(Qt::AlignCenter);
    multiset<pair<int, string>>::iterator it;
    User u;
    qDebug()<< user.standings().begin();
    if(User::currentUserData.league == "Premier League"){
        if(Admin::GAME_WEEK==18){
            user.standings().begin();
            }
    }
    else{
        if(Admin::GAME_WEEK==18){
        }

    }

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

