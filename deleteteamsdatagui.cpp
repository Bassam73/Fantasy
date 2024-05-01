#include "deleteteamsdatagui.h"
#include "ui_deleteteamsdatagui.h"
#include "dataentrygui.h"
#include <iostream>
#include <QtWidgets/QListWidget>
#include "admin.h"
using namespace  std;
DeleteTeamsDataGui::DeleteTeamsDataGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DeleteTeamsDataGui)
{
    ui->setupUi(this);
}

DeleteTeamsDataGui::~DeleteTeamsDataGui()
{
    delete ui;
}

void DeleteTeamsDataGui::on_commandLinkButton_clicked()
{
    close();
    DataEntryGui* dataentryguiDialog = new DataEntryGui();
    dataentryguiDialog->show();
}


void DeleteTeamsDataGui::on_teamLeague_activated(int index)
{
    ui->listWidget->clear();
    QString league = ui->teamLeague->currentText();
    string leagueX = league.toStdString();
    Admin x ;

    if(leagueX=="Premier League"){
        for(int i = 0 ; i< x.plTeamsList.size(); i++){

            QString name= QString::fromStdString( x.plTeamsList[i].name);
            ui->listWidget->addItem(name);
        }
    }
    else if (leagueX =="LaLiga"){
        for(int i = 0 ; i < x.ligaTeamsList.size(); i++){

            QString name= QString::fromStdString( x.ligaTeamsList[i].name);
            ui->listWidget->addItem(name);
        }
    }
}


void DeleteTeamsDataGui::on_pushButton_clicked()
{
    Admin x ;
    QString name = ui->listWidget->currentItem()->text();
    QString league = ui->teamLeague->currentText();
    string nameX = name.toStdString();
    string leagueX = league.toStdString();
    bool check = x.deleteTeam(nameX , leagueX);

    if(check){
        DeleteTeamsDataGui::on_teamLeague_activated(10);
    }
}

