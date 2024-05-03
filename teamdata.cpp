#include "teamdata.h"
#include <QString>
#include "admin.h"
#include <vector>

Admin adder;
TeamData::TeamData() {}
void TeamData::loadData(){
    QFile file("C:/Users/Dell/Fantasy/dataOfTeams.json");
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
                if(leag == "LaLiga")
                adder.ligaTeamsList.push_back(teamData);
                else if (leag == "Premier League")
                adder.plTeamsList.push_back(teamData);

            }
        }
    }
}

void TeamData::storeData(){

    QJsonArray teams;
    for(int i = 0; i < adder.ligaTeamsList.size(); i++){

        QJsonObject team;

        int sid = adder.ligaTeamsList[i].id;
        string sname = adder.ligaTeamsList[i].name;
        string slea = adder.ligaTeamsList[i].league;


        team["id"] =  sid;
        team["name"] =  sname.data();
        team["league"] =  slea.data();

        teams.append(team);

    }
    for(int i = 0; i < adder.plTeamsList.size(); i++){

        QJsonObject team;

        int sid = adder.plTeamsList[i].id;
        string sname = adder.plTeamsList[i].name;
        string slea = adder.plTeamsList[i].league;


        team["id"] =  sid;
        team["name"] =  sname.data();
        team["league"] =  slea.data();

        teams.append(team);

    }

    QJsonDocument doc(teams);
    QFile file("C:/Users/Dell/Fantasy/dataOfTeams.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
    }
}
