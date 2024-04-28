#include "teamdata.h"
#include <QString>
#include "admin.h"
#include <vector>

Admin adder;
TeamData::TeamData() {}
void TeamData::loadData(){
    QFile file("C:/Users/pc/Documents/FantasyProject/Fantasy/dataOfTeams.json");
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

            int id;

            QJsonObject team;
            QString teamName;

            QString league;

            string name;
            string leag;


            for(auto i:arr){
                team = i.toObject();
                id = team.value("id").toInt();
                teamName = team.value("name").toString();

                league = team.value("league").toString();

                name = teamName.toStdString();

                leag = league.toStdString();

                Team teamData(id , name, leag);

                adder.teamsList.push_back(teamData);
            }
        }
    }
}

void TeamData::storeData(){

    QJsonArray teams;
    for(int i = 0; i < adder.teamsList.size(); i++){

        QJsonObject team;

        int sid = adder.teamsList[i].id;
        string sname = adder.teamsList[i].name;
        string slea = adder.teamsList[i].league;


        team["id"] =  sid;
        team["name"] =  sname.data();
        team["league"] =  slea.data();

        teams.append(team);

    }

    QJsonDocument doc(teams);
    QFile file("C:/Users/pc/Documents/FantasyProject/Fantasy/dataOfTeams.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
    }
}
