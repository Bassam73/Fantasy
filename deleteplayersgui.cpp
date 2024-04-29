#include "deleteplayersgui.h"
#include "ui_deleteplayersgui.h"
#include "updateplayers.h"

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

