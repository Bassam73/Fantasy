#include "addteamsdatagui.h"
#include "ui_addteamsdatagui.h"
#include "dataentrygui.h"

AddTeamsDataGui::AddTeamsDataGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddTeamsDataGui)
{
    ui->setupUi(this);
}

AddTeamsDataGui::~AddTeamsDataGui()
{
    delete ui;
}

void AddTeamsDataGui::on_commandLinkButton_clicked()
{
    close();
    DataEntryGui* dataentryguiDialog = new DataEntryGui();
    dataentryguiDialog->show();
}

