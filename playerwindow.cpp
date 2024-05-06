#include "playerwindow.h"
#include "ui_playerwindow.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <qdebug.h>
#include <limits>
#include <QMessageBox>
#include "admin.h"
Admin admi;
User user;
vector<QString> playersInSquad;
string User::CURRENTPOS;
string PlayerWindow::currentPosition;
int PlayerWindow::playersCounter = 0;
PlayerWindow::PlayerWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PlayerWindow)
{
    ui->setupUi(this);
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

    if (currentItem) {

        QString playerName = currentItem->text().split("(").at(0).trimmed();
        for(int i = 0; i < playersInSquad.size();i++){
            qDebug()<<playersInSquad[i];
            if(playerName==playersInSquad[i]){
                QMessageBox addPlayerFailed;
                addPlayerFailed.warning(this ,"Add player Failed" , "Player already in your team");
                return;
            }

        }


        emit playerSelected(playerName);
        playersInSquad.push_back(playerName);
        playersCounter++;
    }
    close();
}
