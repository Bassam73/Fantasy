#include "gameweeksdata.h"
#include <QString>
#include "admin.h"
#include <iostream>
using namespace std;
Admin admin;
GameWeeksData::GameWeeksData() {}

void GameWeeksData::loadData(){
    QFile file("C:/Users/pc/Documents/FantasyProject/Fantasy/dataOfGameWeeks.json");
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
            QJsonObject gameWeek;
            for(auto i:arr){
                gameWeek = i.toObject();

                admin.GAME_WEEK = gameWeek.value("GameWeek").toInt();
            }

        }
    }
}

void GameWeeksData::storeData(){
    QJsonArray GWDATA;
    QJsonObject GameWeek ;
    GameWeek["GameWeek"]=admin.GAME_WEEK;
    GWDATA.append(GameWeek);


    QJsonDocument doc(GWDATA);
    QFile file("C:/Users/pc/Documents/FantasyProject/Fantasy/dataOfGameWeeks.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
    }
}
