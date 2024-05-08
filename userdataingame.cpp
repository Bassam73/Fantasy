#include "userdataingame.h"
#include <QString>
#include "admin.h"
#include "user.h"
#include <vector>
#include <iostream>
using namespace std;
User gamePlay;

userDataInGame::userDataInGame() {}

void userDataInGame::loadData(){
    QFile file("C:/Users/besho/Fantasy/dataOfuserAccount.json");
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

            QJsonArray players;

            QJsonObject user;

            int id;

            QString playerName;
            string name;
            int pId;
            int bank;

            for(auto i:arr){
                user = i.toObject();
                id = user.value("userid").toInt();
                players = user.value("team").toArray();

                QJsonObject play;

                for(auto j:players){

                    play = j.toObject();
                    playerName = play.value("name").toString();
                    name = playerName.toStdString();
                    pId = play.value("id").toInt();

                    gamePlay.userPlayers[id].push_back(name);
                }
            }
        }
    }
}

void userDataInGame::storeData(){

    QJsonArray users;
    for(auto i = gamePlay.userPlayers.begin(); i != gamePlay.userPlayers.end(); i++){

        QJsonObject user;
        QJsonArray players;
        int sid = i->first;

        for(auto pName:i->second){
            QJsonObject play;

            play["name"] = pName.data();
            players.append(play);
        }

        user["userid"] =  sid;
        user["team"] = players;
        // user["bank"] =
        users.append(user);

    }

    QJsonDocument doc(users);
    QFile file("C:/Users/besho/Fantasy/dataOfuserAccount.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
    }
}

