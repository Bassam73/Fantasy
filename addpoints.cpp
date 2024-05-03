#include "addpoints.h"
#include "ui_addpoints.h"
#include "dataentrygui.h"
#include "admin.h"
#include "adminhomegui.h"

#include <qmessagebox.h>
Admin adm;
std::string redCardPlayerName;
static bool mins = true;
static bool cs = true;
static bool redCard = true;
int gameWeek = 1 ;

addpoints::addpoints(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addpoints)
{
    ui->setupUi(this);
    QString gw = QString::number(adm.GAME_WEEK);
    ui->label_3->setText(gw);
}

addpoints::~addpoints()
{
    delete ui;
}

void addpoints::on_commandLinkButton_clicked()
{
    close();
    AdminHomeGui* a = new AdminHomeGui();
    a->show();}


void addpoints::on_comboBox_activated(int index)
{
    ui->comboBox_2->clear();
    if(index == 0){
        for(auto i:adm.plTeamsList){
            QString teamName = i.name.data();
            ui->comboBox_2->addItem(teamName);
        }
    }
    else {
        for(auto i:adm.ligaTeamsList){
            QString teamName = i.name.data();
            ui->comboBox_2->addItem(teamName);
        }
    }
}

void addpoints::on_comboBox_2_activated(int index)
{
    ui->comboBox_4->clear();


        QString selectedTeam = ui->comboBox_2->itemText(index);

        std::string teamName = selectedTeam.toStdString();
        for(const auto& player : adm.teamPlayers[teamName]){
            QString playerName = QString::fromStdString(player.name);
            ui->comboBox_4->addItem(playerName);
        }
}

void addpoints::on_comboBox_4_activated(int index)
{

}
void addpoints::on_comboBox_5_activated(int index) {




}

void addpoints::on_pushButton_clicked()
{
    vector<string> redCardPlayers;
    QString selectedPlayerName = ui->comboBox_4->currentText();
    std::string playerName = selectedPlayerName.toStdString();

    QString action = ui->comboBox_5->currentText();
    int sCase = adm.addPoints(playerName , action);

    switch (sCase) {
    case 1:
        QMessageBox::warning(this , "Action Failed", "Player Has A Red Card");
        break;
    case 2 :
        QMessageBox::warning(this , "Action Failed", "Points Of 60+mins Have Already been Added For This Player");
        break;
    case 3 :
        QMessageBox::warning(this , "Action Failed", "Points Of Clean Cheat Have Already been Added For This Player");
        break;
    default:
         QMessageBox::about(this , "Action Succeed", "Done");
        break;
    }
}


void addpoints::on_commandLinkButton_2_clicked()
{
    adm.nextGameWeek();
    QString gw = QString::number(adm.GAME_WEEK);
    ui->label_3->setText(gw);

}

