#include "adminhomegui.h"
#include "ui_adminhomegui.h"
#include "dataentrygui.h"
#include "updateteamsgui.h"
#include "updateplayers.h"
#include "addpoints.h"
AdminHomeGui::AdminHomeGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminHomeGui)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

}

AdminHomeGui::~AdminHomeGui()
{
    delete ui;
}

void AdminHomeGui::on_pushButton_clicked()
{
    DataEntryGui * d = new DataEntryGui();
    close();
    d->show();
}


void AdminHomeGui::on_pushButton_2_clicked()
{
    UpdateTeamsGui * u = new UpdateTeamsGui();
    close();
    u->show();

}


void AdminHomeGui::on_pushButton_3_clicked()
{
    UpdatePlayers * u = new UpdatePlayers();
    close();
    u->show();
}


void AdminHomeGui::on_pushButton_4_clicked()
{
    addpoints * a = new addpoints();
    close();
    a->show();
}

