#include "deleteplayersgui.h"
#include "ui_deleteplayersgui.h"
#include "updateplayers.h"
#include "admin.h"

#include <qmessagebox.h>

DeletePlayersGui::DeletePlayersGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DeletePlayersGui)
{
    ui->setupUi(this);
}

DeletePlayersGui::~DeletePlayersGui()
{
    delete ui;
}

void DeletePlayersGui::on_commandLinkButton_clicked()
{
    close();
    UpdatePlayers* updateplayersDialog = new UpdatePlayers();
    updateplayersDialog->show();
}


void DeletePlayersGui::on_pushButton_clicked()
{
    int playerID = ui->lineEdit->text().toInt();
    Admin deletePlayer;
    int x = deletePlayer.deletePlayer(deletePlayer.playersList,0,deletePlayer.playersList.size()-1,playerID);
    QMessageBox deletePlayerInfo;
    if(x==1){
        deletePlayerInfo.about(this, "", "player deleted successfully");
    }
    else{
        deletePlayerInfo.warning(this, "", "incorrect ID");
    }

}

