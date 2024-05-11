#include "forgetpasswordgui.h"
#include "ui_forgetpasswordgui.h"
using namespace std;
#include <MainWindow.h>
#include <User.h>
#include <qmessagebox.h>
#include <string>

forgetPasswordgui::forgetPasswordgui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::forgetPasswordgui)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

}

forgetPasswordgui::~forgetPasswordgui()
{
    delete ui;
}

void forgetPasswordgui::on_pushButton_clicked()
{

}

