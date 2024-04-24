#include "registergui.h"
#include "ui_registergui.h"

RegisterGui::RegisterGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterGui)
{
    ui->setupUi(this);
}

RegisterGui::~RegisterGui()
{
    delete ui;
}
