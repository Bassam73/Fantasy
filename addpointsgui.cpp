#include "addpointsgui.h"
#include "ui_addpointsgui.h"

AddPointsGui::AddPointsGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddPointsGui)
{
    ui->setupUi(this);
}

AddPointsGui::~AddPointsGui()
{
    delete ui;
}
