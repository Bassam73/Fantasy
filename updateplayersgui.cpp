#include "updateplayersgui.h"
#include "ui_updateplayersgui.h"
#include "updateplayers.h"
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

