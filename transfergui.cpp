#include "transfergui.h"
#include "ui_transfergui.h"
#include "playerwindow.h"
#include "user.h"

TransferGui::TransferGui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransferGui)
{
    ui->setupUi(this);
    // User::CURRENTPOS = "GK";
    connect(ui->pushButton, &QPushButton::clicked, this, &TransferGui::openPlayerWindow);

}

TransferGui::~TransferGui()
{
    delete ui;
}

void TransferGui::openPlayerWindow() {
    PlayerWindow playerWindow;

    connect(&playerWindow, &PlayerWindow::playerSelected, this, &TransferGui::updateLabel);
    playerWindow.currentPosition="GK";
    playerWindow.exec();
}

void TransferGui::updateLabel(const QString &playerName) {
    ui->updateLabel->setText(playerName);
}


void TransferGui::on_pushButton_clicked()
{
    User::CURRENTPOS= "GK";
}

