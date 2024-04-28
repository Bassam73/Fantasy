#include "dataentrygui.h"
#include "ui_dataentrygui.h"
#include "adminhomegui.h"
#include "editteamsdatagui.h"
#include "deleteteamsdatagui.h"
DataEntryGui::DataEntryGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DataEntryGui)
{
    ui->setupUi(this);
}

DataEntryGui::~DataEntryGui()
{
    delete ui;
}

void DataEntryGui::on_commandLinkButton_clicked()
{
    close();
    AdminHomeGui* a = new AdminHomeGui();
    a->show();
}


void DataEntryGui::on_pushButton_clicked()
{
    close();
    AddTeamsDataGui addteamsdataguiDialog;
    addteamsdataguiDialog.exec();
}


void DataEntryGui::on_pushButton_2_clicked()
{
    close();
    EditTeamsDataGui editteamsdataguiDialog;
    editteamsdataguiDialog.exec();
}


void DataEntryGui::on_pushButton_3_clicked()
{
    close();
    DeleteTeamsDataGui deleteteamsdataguiDialog;
    deleteteamsdataguiDialog.exec();
}

