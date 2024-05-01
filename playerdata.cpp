#include "playerdata.h"
#include <QString>
#include "admin.h"
#include "player.h"
#include <vector>

using namespace std;
Admin adplayer;

PlayerData::PlayerData() {}

void PlayerData::loadData(){

    // Player player;

    // player.initializeMap();

    QFile file("C:/Users/besho/Fantasy/dataOfPlayers.json");

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

            QString playerName;
            QString position;
            QString nationality;
            QString team;

            string name;
            string pos;
            string nation;
            string te;

            qDebug() << arr.size();
            for(auto i:arr){

                play = i.toObject();



                id = play.value("id").toInt();
                kit = play.value("kitnumber").toInt();
                age = play.value("age").toInt();



                playerName = play.value("name").toString();
                position = play.value("position").toString();
                nationality = play.value("nationality").toString();
                team = play.value("team").toString();

                name = playerName.toStdString();
                pos = position.toStdString();
                nation = nationality.toStdString();
                te = team.toStdString();

                Player player1(id , kit, age, name, nation, pos, te);

                adplayer.teamPlayers[te].push_back(player1);

                adplayer.playersList.push_back(player1);

            }
        }
    }

}

void PlayerData::storeData(){

    QJsonArray players;
    for(int i = 0; i < adplayer.playersList.size(); i++){

        QJsonObject player;

        int pId = adplayer.playersList[i].id;
        int pAge = adplayer.playersList[i].age;
        int kitNum = adplayer.playersList[i].kitNumber;

        string pName = adplayer.playersList[i].name;
        string pNation = adplayer.playersList[i].nationality;
        string pTeam = adplayer.playersList[i].team;
        string pPosition = adplayer.playersList[i].position;

        player["id"] =  pId;
        player["age"] =  pAge;
        player["kitnumber"] =  kitNum;

        player["name"] =  pName.data();
        player["position"] =  pPosition.data();
        player["team"] =  pTeam.data();
        player["nationality"] = pNation.data();

        players.append(player);

    }

    QJsonDocument doc(players);
    QFile file("C:/Users/besho/Fantasy/dataOfPlayers.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
    }
}



