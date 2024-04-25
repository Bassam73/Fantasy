#include "logingui.h"
#include "ui_logingui.h"

LoginGui::LoginGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginGui)
{
    ui->setupUi(this);
}

LoginGui::~LoginGui()
{
    delete ui;
}
