#include "deleteteamsdatagui.h"
#include "ui_deleteteamsdatagui.h"
#include "dataentrygui.h"
DeleteTeamsDataGui::DeleteTeamsDataGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DeleteTeamsDataGui)
{
    ui->setupUi(this);
}

DeleteTeamsDataGui::~DeleteTeamsDataGui()
{
    delete ui;
}

void DeleteTeamsDataGui::on_commandLinkButton_clicked()
{
    close();
    DataEntryGui* dataentryguiDialog = new DataEntryGui();
    dataentryguiDialog->show();
}

