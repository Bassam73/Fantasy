#include "transfergui.h"
#include "ui_transfergui.h"
#include "playerwindow.h"

TransferGui::TransferGui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransferGui)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &TransferGui::openPlayerWindow);

}

TransferGui::~TransferGui()
{
    delete ui;
}

void TransferGui::openPlayerWindow() {
    PlayerWindow playerWindow;
    connect(&playerWindow, &PlayerWindow::playerSelected, this, &TransferGui::updateLabel);
    playerWindow.exec();
}

void TransferGui::updateLabel(const QString &playerName) {
    ui->updateLabel->setText(playerName);
}

