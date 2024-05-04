#include "playerwindow.h"
#include "ui_playerwindow.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <limits>

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

    //connect(ui->listWidget, &QListWidget::itemDoubleClicked, this, &PlayerWindow::on_listWidget_itemDoubleClicked);
    connect(ui->okButton, &QPushButton::clicked, this, &PlayerWindow::on_okButton_clicked);
}

PlayerWindow::~PlayerWindow()
{
    delete ui;
}
void PlayerWindow::loadPlayersFromJson() {
    ui->listWidget->clear();
    QFile file("D:/Fantasy/Plplayers.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open JSON file";
        return;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    QJsonArray players = doc.array();

    // Populate team names in combo box
    QStringList teamNames;
    foreach (const QJsonValue &playerValue, players) {
        QJsonObject player = playerValue.toObject();
        QString teamName = player["team"].toString();
        if (!teamNames.contains(teamName)) {
            teamNames << teamName;
        }
    }
    ui->teamComboBox->addItems(teamNames);

    QStringList costFilters = {"Unlimited", "14.0", "13.5", "13.0", "12.5", "12.0", "11.5", "11.0",
                               "10.5", "10.0", "9.5", "9.0", "8.5", "8.0", "7.5", "7.0", "6.5",
                               "6.0", "5.5", "5.0", "4.5", "4.0", "3.5", "3.0"};
    ui->costComboBox->addItems(costFilters);

    foreach (const QJsonValue &playerValue, players) {
        QJsonObject player = playerValue.toObject();
        QString playerName = player["name"].toString();
        double playerCost = player["cost"].toDouble();
        QString playerTeam = player["team"].toString();
        QString playerPosition = player["position"].toString();

        if (playerPosition == "GK") {
            QString playerInfo = playerName + " (" + playerTeam + ") (Cost: $" + QString::number(playerCost, 'f', 2) + ")";
            ui->listWidget->addItem(playerInfo);
        }
    }
}

void PlayerWindow::filterPlayersByTeam(const QString &teamName) {
    ui->listWidget->clear();

    QFile file("D:/New folder/Fantasy1/Plplayers.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open JSON file";
        return;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    QJsonArray players = doc.array();

    if (teamName == "All Teams") {
        foreach (const QJsonValue &playerValue, players) {
            QJsonObject player = playerValue.toObject();
            QString playerName = player["name"].toString();
            double playerCost = player["cost"].toDouble();
            QString playerTeam = player["team"].toString();
            QString playerPosition = player["position"].toString();

            if (playerPosition == "GK") {
                QString playerInfo = playerName + " (" + playerTeam + ") (Cost: $" + QString::number(playerCost, 'f', 2) + ")";
                ui->listWidget->addItem(playerInfo);
            }
        }
    } else {
        foreach (const QJsonValue &playerValue, players) {
            QJsonObject player = playerValue.toObject();
            QString playerName = player["name"].toString();
            QString playerTeam = player["team"].toString();
            double playerCost = player["cost"].toDouble();
            QString playerPosition = player["position"].toString();

            if (playerTeam == teamName && playerPosition == "GK") {
                QString playerInfo = playerName + " (Cost: $" + QString::number(playerCost, 'f', 2) + ")";
                ui->listWidget->addItem(playerInfo);
            }
        }
    }
}

void PlayerWindow::filterPlayersByCostFilter(const QString &costFilter) {
    ui->listWidget->clear();

    QFile file("D:/New folder/Fantasy1/Plplayers.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open JSON file";
        return;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    QJsonArray players = doc.array();

    double maxCost = std::numeric_limits<double>::infinity();
    if (costFilter != "Unlimited") {
        maxCost = costFilter.toDouble();
    }

    QString selectedTeam = ui->teamComboBox->currentText();
    foreach (const QJsonValue &playerValue, players) {
        QJsonObject player = playerValue.toObject();
        QString playerName = player["name"].toString();
        QString playerTeam = player["team"].toString();
        double playerCost = player["cost"].toDouble();
        QString playerPosition = player["position"].toString();

        if (playerPosition == "GK" && (selectedTeam == "All Teams" || playerTeam == selectedTeam) &&
            playerCost <= maxCost) {
            if(selectedTeam == "All Teams") {
                QString playerInfo = playerName + " (" + playerTeam + ") (Cost: $" + QString::number(playerCost, 'f', 2) + ")";
                ui->listWidget->addItem(playerInfo);
            } else {
                QString playerInfo = playerName + " (Cost: $" + QString::number(playerCost, 'f', 2) + ")";
                ui->listWidget->addItem(playerInfo);
            }
        }
    }
}

//void PlayerWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item) {
// emit playerSelected(item->text());
//}

void PlayerWindow::on_okButton_clicked() {
    QListWidgetItem *currentItem = ui->listWidget->currentItem();
    if (currentItem) {
        QString playerName = currentItem->text().split(" ").at(0);
        emit playerSelected(playerName);
    }

    close();
}
