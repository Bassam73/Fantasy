#include "dataentrygui.h"
#include "ui_dataentrygui.h"
#include "adminhomegui.h"
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

