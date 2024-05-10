#include "playerwindow.h"
#include "ui_playerwindow.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <qdebug.h>
#include <limits>
#include <QMessageBox>
#include "transfergui.h"
#include "admin.h"
Admin admi;
User user;
QVector<QString> PlayerWindow::playersInSquad;
string User::CURRENTPOS;
string PlayerWindow::currentPosition;
// int PlayerWindow::playersCounter = User::usersTeam.size();
PlayerWindow::PlayerWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PlayerWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    connect(ui->teamComboBox, QOverload<int>::of(&QComboBox::activated),
            [this](int index){
                QString teamName = ui->teamComboBox->itemText(index);
                if (teamName.isEmpty()) {
                    loadPlayersFromJson();
                } else {
                    filterPlayersByTeam(teamName);
                }
            });

    connect(ui->costComboBox, QOverload<int>::of(&QComboBox::activated),
            [this](int index){
                QString costFilter = ui->costComboBox->itemText(index);
                filterPlayersByCostFilter(costFilter);
            });

    loadPlayersFromJson();

    // connect(ui->okButton, &QPushButton::clicked, this /*&PlayerWindow::on_okButton_clicked*/);
}

PlayerWindow::~PlayerWindow()
{
    delete ui;
}
void PlayerWindow::loadPlayersFromJson() {
    ui->listWidget->clear();

    QStringList teamNames = user.getTeams();


    ui->teamComboBox->clear();
    ui->teamComboBox->addItems(teamNames);

    ui->costComboBox->clear();
    QStringList costFilters = {"Unlimited", "14.0", "13.5", "13.0", "12.5", "12.0", "11.5", "11.0",
                               "10.5", "10.0", "9.5", "9.0", "8.5", "8.0", "7.5", "7.0", "6.5",
                               "6.0", "5.5", "5.0", "4.5", "4.0", "3.5", "3.0"};
    ui->costComboBox->addItems(costFilters);

    qDebug()<<User::CURRENTPOS;
     QStringList players = user.getPlayers();

    for(auto player : players){
         ui->listWidget->addItem(player);
    }
}



void PlayerWindow::filterPlayersByTeam(const QString &teamName) {
    ui->listWidget->clear();
    if (teamName == "All Teams") {
        loadPlayersFromJson();
    } else {

        QStringList players = user.filterPlayersByTeam(teamName);
        for(auto player : players){
            ui->listWidget->addItem(player);
        }
    }
}

void PlayerWindow::filterPlayersByCostFilter(const QString &costFilter) {
    ui->listWidget->clear();

    QString selectedTeam = ui->teamComboBox->currentText();

    QStringList players = user.filterPlayersByCost(costFilter , selectedTeam);

    for(auto player : players){
               ui->listWidget->addItem(player);
    }
}

void PlayerWindow::on_okButton_clicked() {
    QListWidgetItem *currentItem = ui->listWidget->currentItem();
    QMessageBox addPlayerFailed;
    if (currentItem) {


        QString playerName = currentItem->text().split("(").at(0).trimmed();
        double playerCost  = currentItem->text().split("$").at(1).split(" ").at(0).toDouble();
        double &userBank = user.currentUserData.bank;
        // qDebug() << playerCost;

        // for(auto i = User::usersTeam.begin(); i != User::usersTeam.end(); i++){

        //     // qDebug()<<playersInSquad[i];
        //     if(i->first == playerName.toStdString()){

        //         addPlayerFailed.warning(this ,"Add player Failed" , "Player already in your team");
        //         return;
        //     }
        // }
        qDebug() << "2abl";
        for(int i = 0; i < TransferGui::labels.size();i++){
            qDebug()<<TransferGui::labels[i];
            if(playerName==TransferGui::labels[i]){

                addPlayerFailed.warning(this ,"Add player Failed" , "Player already in your team");
                return;
            }
        }

        if(playerCost > user.currentUserData.bank){
            addPlayerFailed.warning(this ,"Add player Failed" , "Player Cost is greater than your money");
            return;
        }

        userBank -= playerCost;

        emit playerSelected(playerName, userBank);



        // playersInSquad.push_back(playerName);


        qDebug() << admi.usersList[user.userIndex].bank << user.userIndex;
    }
    close();
}

