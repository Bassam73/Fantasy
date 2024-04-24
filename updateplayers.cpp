#include "updateplayers.h"
#include "ui_updateplayers.h"
#include "adminhomegui.h"
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

