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

            int pId;
            int kit;
            int age;

            QString playerName;
            QString position;
            QString team;

            string name;
            string pos;
            string te;
            float co;

            for(auto i:arr){
                user = i.toObject();
                id = user.value("userid").toInt();
                players = user.value("team").toArray();

                QJsonObject play;

                for(auto j:players){


                    play = j.toObject();

                    pId = play.value("id").toInt();
                    // kit = play.value("kitnumber").toInt();
                    // age = play.value("age").toInt();
                    // co=play.value("cost").toDouble();

                    // playerName = play.value("name").toString();
                    // position = play.value("position").toString();
                    // team = play.value("team").toString();


                    // name = playerName.toStdString();
                    // pos = position.toStdString();
                    // te = team.toStdString();

                    // Player player(id , kit, age, name, pos, te,co);

                    gamePlay.userPlayers[id].push_back(pId);
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

        for(auto pId:i->second){
            QJsonObject play;

            // int pId = j;
            // int kit = j.kitNumber;
            // int age = j.age;
            // float co = j.cost;

            // string name = j.name;
            // string pos = j.position;
            // string te = j.team;
            play["id"] = pId;
            // play["name"] = name.data();
            // play["age"] = age;
            // play["kit number"] = kit;
            // play["cost"] = co;
            // play["position"] = pos.data();
            // play["team"] = te.data();
            players.append(play);
        }

        user["userid"] =  sid;
        user["team"] = players;
        users.append(user);

    }

    QJsonDocument doc(users);
    QFile file("C:/Users/besho/Fantasy/dataOfuserAccount.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
    }
}

