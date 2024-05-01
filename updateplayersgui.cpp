#include "updateplayersgui.h"
#include "ui_updateplayersgui.h"
#include "updateplayers.h"
#include "admin.h"

#include <qmessagebox.h>
UpdatePLayersGui::UpdatePLayersGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UpdatePLayersGui)
{
    ui->setupUi(this);
}

UpdatePLayersGui::~UpdatePLayersGui()
{
    delete ui;
}

void UpdatePLayersGui::on_commandLinkButton_clicked()
{
    close();
    UpdatePlayers* updateplayersDialog = new UpdatePlayers();
    updateplayersDialog->show();
}


void UpdatePLayersGui::on_pushButton_clicked()
{
    int playerID = ui->lineEdit->text().toInt();
    int age = ui->lineEdit_3->text().toInt();
    int kitNumber = ui->lineEdit_2->text().toInt();
    string position = ui->comboBox->currentText().toStdString();
    Admin updatePlayer;
    int x = updatePlayer.updatePlayers(updatePlayer.playersList,0,updatePlayer.playersList.size()-1,playerID,age,kitNumber,position);
    QMessageBox updatePlayerInfo;
    if(age==0&& kitNumber==0 &&position.empty()){
        updatePlayerInfo.about(this, "", "please change player data");
    }
    else{
        if(x==1){
            updatePlayerInfo.about(this, "", "player updated successfully");
        }
        else{
            updatePlayerInfo.warning(this, "", "incorrect ID");
        }
    }
}

