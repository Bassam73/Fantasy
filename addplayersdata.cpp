#include "addplayersdata.h"
#include "ui_addplayersdata.h"
#include "updateplayers.h"
#include "admin.h"
#include <QString>
#include <QMessageBox>

Admin adPlayers;

AddPlayersData::AddPlayersData(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddPlayersData)
{
    ui->setupUi(this);
}

AddPlayersData::~AddPlayersData()
{
    delete ui;
}

void AddPlayersData::on_commandLinkButton_clicked()
{
    close();
    UpdatePlayers* updateplayersDialog = new UpdatePlayers();
    updateplayersDialog->show();
}


void AddPlayersData::on_comboBox_activated(int index)
{
    ui->comboBox_2->clear();
    if(index == 0){
        for(auto i:adPlayers.plTeamsList){
            QString teamName = i.name.data();
            ui->comboBox_2->addItem(teamName);
        }
    }
    else {
        for(auto i:adPlayers.ligaTeamsList){
            QString teamName = i.name.data();
            ui->comboBox_2->addItem(teamName);
        }
    }
}


void AddPlayersData::on_pushButton_clicked()
{
    QMessageBox incorrectPlayerData;

    QString team = ui->comboBox_2->currentText();
    QString position = ui->comboBox_3->currentText();
    QString name = ui->lineEdit_2->text();
    QString age = ui->lineEdit_3->text();
    QString kitnum = ui->lineEdit_4->text();
    QString cost = ui->lineEdit_5->text();
    // float playerCost = sCost.toFloat();


    if(team.isEmpty() ||
        position.isEmpty() ||
        cost.isEmpty() ||
        name.isEmpty()||
        age.isEmpty()||
        kitnum.isEmpty()){

        incorrectPlayerData.warning(this, "Add Data Failed", "Please fill data.");

    }else{

        int code = adPlayers.addPlayer(name.toStdString(),
                                       position.toStdString(),
                                       team.toStdString(),
                                       age.toInt(),
                                       kitnum.toInt(),
                                       cost.toFloat()
                                       );

        if(code == 1){
            incorrectPlayerData.warning(this, "Add Data Failed", "The Kit Number must be less than 100.");
        }
        else if(code == 2){
            incorrectPlayerData.warning(this, "Add Data Failed", "The Kit Number is already exist.");
        }
        else {
            incorrectPlayerData.about(this, "", "Data added successfully");
        }
    }

}

