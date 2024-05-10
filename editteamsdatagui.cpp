#include "editteamsdatagui.h"
#include "ui_editteamsdatagui.h"
#include "dataentrygui.h"
EditTeamsDataGui::EditTeamsDataGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditTeamsDataGui)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

}

EditTeamsDataGui::~EditTeamsDataGui()
{
    delete ui;
}

void EditTeamsDataGui::on_commandLinkButton_clicked()
{
    close();
    DataEntryGui* dataentryguiDialog = new DataEntryGui();
    dataentryguiDialog->show();
}

