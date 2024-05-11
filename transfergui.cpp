#include "transfergui.h"
#include "ui_transfergui.h"
#include "playerwindow.h"
#include "user.h"
#include "team.h"
#include "admin.h"
#include <vector>
#include <QMessageBox>
#include "mainwindow.h"

User userd;
// Admin admi;
Team team;
QVector<QString> TransferGui::labels;


TransferGui::TransferGui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransferGui)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

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

    this->setPlayers();
    User::currentUserData.bank = Admin::usersList[User::userIndex].bank;
    ui->label_3->setText("Bank: " + QString::number(User::currentUserData.bank, 'f', 1) + "$");
    ui->label_4->setText("GW : "+ QString::number(Admin::GAME_WEEK));

}



TransferGui::~TransferGui()
{
    delete ui;
}


void TransferGui::openPlayerWindow() {
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (!clickedButton) return;

    PlayerWindow playerWindow;

    connect(&playerWindow, &PlayerWindow::playerSelected, this, [=](const QString &playerName, double userBank ){
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
        labels.clear();
        qDebug()<<"itmasa7";
        labels.push_back(ui->updateLabel->text());
        labels.push_back(ui->updateLabel_2->text());
        labels.push_back(ui->updateLabel_3->text());
        labels.push_back(ui->updateLabel_4->text());
        labels.push_back(ui->updateLabel_5->text());
        labels.push_back(ui->updateLabel_6->text());
        labels.push_back(ui->updateLabel_7->text());
        labels.push_back(ui->updateLabel_8->text());
        labels.push_back(ui->updateLabel_9->text());
        labels.push_back(ui->updateLabel_10->text());
        labels.push_back(ui->updateLabel_11->text());
        ui->label_3->setText("Bank: " + QString::number(userBank, 'f', 1) + "$");
        ui->label_4->setText("GW : "+ QString::number(Admin::GAME_WEEK));

    });
    playerWindow.exec();
}

void TransferGui::on_commandLinkButton_clicked()
{
    close();
    MainWindow* mainwindowDialog = new MainWindow();
    mainwindowDialog->show();
}

void TransferGui::on_pushButton_clicked()
{
    User::CURRENTPOS= "GK";
    userd.bankHandling(ui->updateLabel->text());
}

void TransferGui::on_pushButton_2_clicked()
{
    User::CURRENTPOS= "DEF";
    userd.bankHandling(ui->updateLabel_2->text());
}

void TransferGui::on_pushButton_3_clicked()
{
    User::CURRENTPOS= "DEF";
    userd.bankHandling(ui->updateLabel_3->text());
}


void TransferGui::on_pushButton_4_clicked()
{
    User::CURRENTPOS= "DEF";
    userd.bankHandling(ui->updateLabel_4->text());
}


void TransferGui::on_pushButton_5_clicked()
{
    User::CURRENTPOS= "DEF";
    userd.bankHandling(ui->updateLabel_5->text());

}


void TransferGui::on_pushButton_6_clicked()
{
    User::CURRENTPOS= "MID";
    userd.bankHandling(ui->updateLabel_6->text());
}


void TransferGui::on_pushButton_7_clicked()
{
    User::CURRENTPOS= "MID";
    userd.bankHandling(ui->updateLabel_7->text());
}


void TransferGui::on_pushButton_8_clicked()
{
    User::CURRENTPOS= "MID";
    userd.bankHandling(ui->updateLabel_8->text());
}


void TransferGui::on_pushButton_9_clicked()
{
    User::CURRENTPOS= "ATT";
    userd.bankHandling(ui->updateLabel_9->text());
}


void TransferGui::on_pushButton_10_clicked()
{
    User::CURRENTPOS= "ATT";
    userd.bankHandling(ui->updateLabel_10->text());
}


void TransferGui::on_pushButton_11_clicked()
{
    User::CURRENTPOS= "ATT";
    userd.bankHandling(ui->updateLabel_11->text());
}

void TransferGui::on_pushButton_12_clicked()
{
    int count = 0 /*PlayerWindow::playersCounter*/;

    qDebug() << labels.size();
    for(auto i:labels){
        if(i.toStdString() != "")
            count++;
        else
            PlayerWindow::playersInSquad.push_back(i);
    }
    qDebug() << count;


    if(count<3){
        QMessageBox saveTransfersFailed;
        saveTransfersFailed.warning(this ,"Save Failed" , "You must have at least 3 players in your team");

    }
    else{


        // labels =
        User::userPlayers[User::currentUserData.id].clear();
        User::usersTeam.clear();

        QVector<QString> qVectorLabels = labels.toVector();
        std::vector<QString> stdVectorLabels(qVectorLabels.begin(), qVectorLabels.end());

        team.savePlayers(stdVectorLabels);
        qDebug() << User::usersTeam.size();
        // User::usersTeam[ui->updateLabel->text()] =
        Admin::usersList[User::userIndex].bank = User::currentUserData.bank;

    }
}
void TransferGui::setPlayers(){
    TransferGui::labels.clear();
    for(auto i = User::usersTeam.begin(); i != User::usersTeam.end(); i++){
        QString playerName = QString::fromStdString(i->first);
        if(i->second.position == "ATT"){
            if(ui->updateLabel_9->text() == ""){
                ui->updateLabel_9->setText(playerName);
            }
            else if(ui->updateLabel_10->text() == ""){
                ui->updateLabel_10->setText(playerName);
            }
            else{
                ui->updateLabel_11->setText(playerName);
            }

        }
        else if(i->second.position == "MID"){
            if(ui->updateLabel_6->text() == ""){
                ui->updateLabel_6->setText(playerName);
            }
            else if(ui->updateLabel_7->text() == ""){
                ui->updateLabel_7->setText(playerName);
            }
            else{
                ui->updateLabel_8->setText(playerName);
            }
        }
        else if(i->second.position == "DEF"){
            if(ui->updateLabel_2->text() == ""){
                ui->updateLabel_2->setText(playerName);
            }
            else if(ui->updateLabel_3->text() == ""){
                ui->updateLabel_3->setText(playerName);
            }
            else if(ui->updateLabel_4->text() == ""){
                ui->updateLabel_4->setText(playerName);
            }
            else{
                ui->updateLabel_5->setText(playerName);
            }

        }
        else if(i->second.position == "GK"){
            ui->updateLabel->setText(playerName);

        }
        TransferGui::labels.push_back(playerName);
    }
}


void TransferGui::on_pushButton_13_clicked()
{
    qDebug()<<User::currentUserData.luckyWheelUsed;
    if(User::currentUserData.luckyWheelUsed){
        QMessageBox::about(this , "Failed", "You have already used lucky wheel");
        return;
    }
    Admin a ;
    a.luckyWheel();

    TransferGui * x  = new TransferGui;
    this->close();
    x->show();

}

