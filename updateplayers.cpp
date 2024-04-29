#include "updateplayers.h"
#include "ui_updateplayers.h"
#include "adminhomegui.h"
#include "addplayersdata.h"
#include "deleteplayersgui.h"
#include "updateplayersgui.h"

UpdatePlayers::UpdatePlayers(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UpdatePlayers)
{
    ui->setupUi(this);
}

UpdatePlayers::~UpdatePlayers()
{
    delete ui;
}

void UpdatePlayers::on_commandLinkButton_clicked()
{
    close();
    AdminHomeGui* a = new AdminHomeGui();
    a->show();
}


void UpdatePlayers::on_pushButton_clicked()
{
    close();
    AddPlayersData addplayersdataDialog;
    addplayersdataDialog.exec();
}


void UpdatePlayers::on_pushButton_2_clicked()
{
    close();
    DeletePlayersGui deleteplayersguiDialog;
    deleteplayersguiDialog.exec();
}


void UpdatePlayers::on_pushButton_3_clicked()
{
    close();
    UpdatePLayersGui updateplayersguiDialog;
    updateplayersguiDialog.exec();
}

