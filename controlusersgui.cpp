#include "controlusersgui.h"
#include "ui_controlusersgui.h"
#include "adminhomegui.h"
ControlUsersGui::ControlUsersGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ControlUsersGui)
{
    ui->setupUi(this);
}

ControlUsersGui::~ControlUsersGui()
{
    delete ui;
}

void ControlUsersGui::on_commandLinkButton_clicked()
{
    close();
    AdminHomeGui* a = new AdminHomeGui();
    a->show();
}

