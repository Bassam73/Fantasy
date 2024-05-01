#include "addpoints.h"
#include "ui_addpoints.h"
#include "dataentrygui.h"
#include "admin.h"
#include "adminhomegui.h"
Admin adm;
std::string redCardPlayerName;
static bool mins = true;
static bool cs = true;
static bool redCard = true;

addpoints::addpoints(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addpoints)
{
    ui->setupUi(this);
}

addpoints::~addpoints()
{
    delete ui;
}

void addpoints::on_commandLinkButton_clicked()
{
    close();
    AdminHomeGui* a = new AdminHomeGui();
    a->show();}


void addpoints::on_comboBox_activated(int index)
{
    ui->comboBox_2->clear();
    if(index == 0){
        for(auto i:adm.plTeamsList){
            QString teamName = i.name.data();
            ui->comboBox_2->addItem(teamName);
        }
    }
    else {
        for(auto i:adm.ligaTeamsList){
            QString teamName = i.name.data();
            ui->comboBox_2->addItem(teamName);
        }
    }
}

void addpoints::on_comboBox_2_activated(int index)
{
    ui->comboBox_4->clear();


        QString selectedTeam = ui->comboBox_2->itemText(index);

        std::string teamName = selectedTeam.toStdString();
        for(const auto& player : adm.teamPlayers[teamName]){
            QString playerName = QString::fromStdString(player.name);
            ui->comboBox_4->addItem(playerName);
        }

    // else {
    //     for(auto i:adm.ligaTeamsList){
    //         QString teamName = i.name.data();
    //         ui->comboBox_2->addItem(teamName);
    //     }
    // }
}

void addpoints::on_comboBox_4_activated(int index)
{
//     QString selectedPlayer = ui->comboBox_4->itemText(index);
//     std::string playerName = selectedPlayer.toStdString();

//     auto playerIt = std::find_if(adm.playersList.begin(), adm.playersList.end(),
//                            [&](const Player& player) { return player.name == playerName; });

//     if (playerIt != adm.playersList.end()) {

//         playerIt->points = 4;
//         cout << playerIt->points << endl;
//     } else {

//     }
}
// Declare redCardPlayerName outside the function (at the class level)
void addpoints::on_comboBox_5_activated(int index) {
    vector<string> redCardPlayers;
    QString selectedPlayerName = ui->comboBox_4->currentText();
    std::string playerName = selectedPlayerName.toStdString();

    QString action = ui->comboBox_5->currentText();

  auto playerIt = std::find_if(adm.playersList.begin(), adm.playersList.end(),
                           [&](const Player& player) { return player.name == playerName; });


    if (playerIt != adm.playersList.end()) {
        // Initialize flags and variables outside the function
        static int yc = 0;
        bool carded = false;
        static bool cleanSheetApplied = false;
        static bool minsApplied = false;

        // Check if the player has a red card
        if (redCard && playerIt->name == redCardPlayerName) {
            cout << "Player " << playerIt->name << " has a red card. No further actions allowed." << endl;
            return;
        }

        // Process other actions
        if (action == "60+ min" && mins && !minsApplied) {
            minsApplied = true;
            playerIt->points += 2;
        } else if (action == "Assist") {
            playerIt->points += 3;
        } else if (action == "Red Card") {
            redCard = true;
            redCardPlayerName = playerIt->name; // Store the player name with the red card
            playerIt->points -= 3;
            redCardPlayers.push_back(playerIt->name);
        } else if (action == "Yellow Card" && yc < 2) {
            playerIt->points -= 1;
            yc++;
        } else if ((playerIt->position == "GK" || playerIt->position == "DEF") && action == "Goal") {
            playerIt->points += 6;
        } else if (action == "Clean Sheet" && cs && !cleanSheetApplied) {
            cleanSheetApplied = true;
            cs = false;
            playerIt->points += 4;
        }

        cout << playerIt->name << " " << playerIt->points << endl;
    }
}
