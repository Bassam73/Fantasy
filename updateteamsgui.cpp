#include "updateteamsgui.h"
#include "ui_updateteamsgui.h"
#include "adminhomegui.h"
UpdateTeamsGui::UpdateTeamsGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UpdateTeamsGui)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

}

UpdateTeamsGui::~UpdateTeamsGui()
{
    delete ui;
}

void UpdateTeamsGui::on_commandLinkButton_clicked()
{
    close();
    AdminHomeGui* a = new AdminHomeGui();
    a->show();
}

