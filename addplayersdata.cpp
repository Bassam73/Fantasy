#include "addplayersdata.h"
#include "ui_addplayersdata.h"
#include "updateplayers.h"

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

