#include "transfergui.h"
#include "ui_transfergui.h"
#include "playerwindow.h"
#include "user.h"
#include "mainwindow.h"

TransferGui::TransferGui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransferGui)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &TransferGui::openPlayerWindow);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &TransferGui::openPlayerWindow);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &TransferGui::openPlayerWindow);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &TransferGui::openPlayerWindow);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &TransferGui::openPlayerWindow);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &TransferGui::openPlayerWindow);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &TransferGui::openPlayerWindow);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &TransferGui::openPlayerWindow);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &TransferGui::openPlayerWindow);
    connect(ui->pushButton_10, &QPushButton::clicked, this, &TransferGui::openPlayerWindow);
    connect(ui->pushButton_11, &QPushButton::clicked, this, &TransferGui::openPlayerWindow);

}

TransferGui::~TransferGui()
{
    delete ui;
}

void TransferGui::openPlayerWindow() {
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (!clickedButton) return;

    PlayerWindow playerWindow;

    connect(&playerWindow, &PlayerWindow::playerSelected, this, [=](const QString &playerName){
        if (clickedButton == ui->pushButton) {
            ui->updateLabel->setText(playerName);
        } else if (clickedButton == ui->pushButton_2) {
            ui->updateLabel_3->setText(playerName);
        }else if (clickedButton == ui->pushButton_3) {
            ui->updateLabel_2->setText(playerName);
        }else if (clickedButton == ui->pushButton_4) {
            ui->updateLabel_4->setText(playerName);
        }else if (clickedButton == ui->pushButton_5) {
            ui->updateLabel_5->setText(playerName);
        }else if (clickedButton == ui->pushButton_6) {
            ui->updateLabel_6->setText(playerName);
        }else if (clickedButton == ui->pushButton_7) {
            ui->updateLabel_7->setText(playerName);
        }else if (clickedButton == ui->pushButton_8) {
            ui->updateLabel_8->setText(playerName);
        }else if (clickedButton == ui->pushButton_9) {
            ui->updateLabel_9->setText(playerName);
        }else if (clickedButton == ui->pushButton_10) {
            ui->updateLabel_10->setText(playerName);
        }else if (clickedButton == ui->pushButton_11) {
            ui->updateLabel_11->setText(playerName);
        }
    });
    playerWindow.exec();
}

void TransferGui::on_pushButton_clicked()
{
    User::CURRENTPOS= "GK";
}


void TransferGui::on_commandLinkButton_clicked()
{
    close();
    MainWindow* mainwindowDialog = new MainWindow();
    mainwindowDialog->show();
}


void TransferGui::on_pushButton_2_clicked()
{
    User::CURRENTPOS= "DEF";
}

void TransferGui::on_pushButton_3_clicked()
{
    User::CURRENTPOS= "DEF";

}


void TransferGui::on_pushButton_4_clicked()
{
    User::CURRENTPOS= "DEF";

}


void TransferGui::on_pushButton_5_clicked()
{
    User::CURRENTPOS= "DEF";

}


void TransferGui::on_pushButton_6_clicked()
{
    User::CURRENTPOS= "MID";

}


void TransferGui::on_pushButton_7_clicked()
{
    User::CURRENTPOS= "MID";

}


void TransferGui::on_pushButton_8_clicked()
{
    User::CURRENTPOS= "MID";

}


void TransferGui::on_pushButton_9_clicked()
{
    User::CURRENTPOS= "ATT";

}


void TransferGui::on_pushButton_10_clicked()
{
    User::CURRENTPOS= "ATT";

}


void TransferGui::on_pushButton_11_clicked()
{
    User::CURRENTPOS= "ATT";

}

