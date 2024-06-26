#include "gameweeksdata.h"
#include <QString>
#include "admin.h"
#include <iostream>
using namespace std;
Admin admin;
GameWeeksData::GameWeeksData() {}

void GameWeeksData::loadData(){
    QString path = QString::fromStdString(admin.gameWeeksDataPath);
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
            QJsonObject gameWeek;
            for(auto i:arr){
                gameWeek = i.toObject();

                admin.GAME_WEEK = gameWeek.value("GameWeek").toInt();
            }

        }
    }
}

void GameWeeksData::storeData(){
        QString path = QString::fromStdString(admin.gameWeeksDataPath);
    QJsonArray GWDATA;
    QJsonObject GameWeek ;
    GameWeek["GameWeek"]=admin.GAME_WEEK;
    GWDATA.append(GameWeek);


    QJsonDocument doc(GWDATA);
    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
    }
}
