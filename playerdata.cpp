#include "playerdata.h"
#include <QString>
#include "admin.h"
#include "player.h"
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include "string"
using namespace std;
Admin adplayer;

PlayerData::PlayerData() {}

void PlayerData::loadData(){
    QString path = QString::fromStdString(adplayer.plPlayersDataPath);
    QFile file(path);

    if(file.open(QIODevice::ReadOnly)){

        QByteArray Bytes = file.readAll();
        file.close();
        QJsonParseError JsonError;
        QJsonDocument Document =QJsonDocument::fromJson(Bytes, &JsonError);

        if(JsonError.error != QJsonParseError::NoError){
            qDebug() << "Error is : " << JsonError.errorString();
            return;
        }
        else {
            qDebug() << "no error";
        }

        if (Document.isArray()){

            QJsonArray arr = Document.array();
            QJsonObject play;

            int id;
            int kit;
            int age;

            int goals;
            int assists;
            int cleanSheets;
            int yellowCards;

            QString playerName;
            QString position;
            QString team;

            string name;
            string pos;
            string te;
            float co;
            int points;

            map <int  , int> gw;

            qDebug() << arr.size();
            for(auto i:arr){

                play = i.toObject();



                id = play.value("id").toInt();
                kit = play.value("kitnumber").toInt();
                goals = play.value("Goals").toInt();
                assists = play.value("Assists").toInt();
                cleanSheets = play.value("cleanSheets").toInt();
                yellowCards = play.value("yellowCards").toInt();


                co=play.value("cost").toDouble();

                for (int i = 1; i < 19; ++i) {
                    std::string week = "GameWeek" + std::to_string(i);
                    gw[i] = play.value(QString::fromStdString(week)).toInt();
                    // cout<<gw[i];
                }

                playerName = play.value("name").toString();
                position = play.value("position").toString();
                team = play.value("team").toString();


                name = playerName.toStdString();
                pos = position.toStdString();
                te = team.toStdString();
                points=play.value("points").toInt();

                Player player1(id , kit, age, name, pos, te,gw,co,points , goals , assists , cleanSheets , yellowCards);

                adplayer.teamPlayers[te].push_back(player1);

                adplayer.playersList.push_back(player1);

            }
        }
    }

}

void PlayerData::storeData() {
    QJsonArray players;
    unordered_map<string, unordered_set<int>> teamKitNumbers;
    QString path = QString::fromStdString(adplayer.plPlayersDataPath);

    for (int i = 0; i < adplayer.playersList.size(); i++) {
        QJsonObject player;

        int pId = adplayer.playersList[i].id;
        // int kitNum = adplayer.playersList[i].kitNumber;
        int pAge = adplayer.playersList[i].age;

        int pGoals = adplayer.playersList[i].goals;
        int pAssists = adplayer.playersList[i].assists;
        int pCleanSheets = adplayer.playersList[i].cleanSheets;
        int pYellowCards = adplayer.playersList[i].yellowCards;

        int points = adplayer.playersList[i].points;
        double cost = roundf(adplayer.playersList[i].cost * 10.0)/10.0;
        string pName = adplayer.playersList[i].name;
        string pTeam = adplayer.playersList[i].team;
        string pPosition = adplayer.playersList[i].position;

        int kitNum;
        if (teamKitNumbers.find(pTeam) == teamKitNumbers.end()) {
            teamKitNumbers[pTeam] = {};
        }
        do {
            kitNum = std::rand() % 100 + 1;
        } while (teamKitNumbers[pTeam].count(kitNum) > 0);
        teamKitNumbers[pTeam].insert(kitNum);

        player["id"] = pId;
        player["age"] = pAge;

        player["Goals"] = pGoals;
        player["Assists"] = pAssists;
        player["cleanSheets"] = pCleanSheets;
        player["yellowCards"] = pYellowCards;

        player["kitnumber"] = kitNum;
        player["points"] = points;
        player["cost"] = cost;
        player["name"] = QString::fromStdString(pName);
        for (int j = 1; j < 19; j++) {
            QString weekKey = "GameWeek" + QString::number(j);
            player[weekKey] = adplayer.playersList[i].gwPoints[j];
        }

        player["position"] = QString::fromStdString(pPosition);
        player["team"] = QString::fromStdString(pTeam);

        players.append(player);
    }

    QJsonDocument doc(players);
    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
    }
}





