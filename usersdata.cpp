#include "usersdata.h"
#include <QString>
#include "admin.h"
#include "user.h"
#include <vector>
using namespace std;
Admin addData;
User userData;

UsersData::UsersData()
{

}

void UsersData::loadData(){

    QString path = QString::fromStdString(addData.usersDataPath);
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

            int id;
            int points;
            double bank;


            QJsonObject user;
            QString userName;
            QString password;
            QString league;

            string name;
            string pass;
            string leag;


            for(auto i:arr){
                user = i.toObject();
                id = user.value("id").toInt();
                userName = user.value("name").toString();
                password = user.value("password").toString();
                league = user.value("league").toString();
                bank = user.value("bank").toDouble();
                points=user.value("points").toInt();
                // if (bank == NULL){
                //     bank = 100;
                // }

                name = userName.toStdString();
                pass = password.toStdString();
                leag = league.toStdString();

                User userData(id ,points, name, pass, leag, bank);

                addData.usersList.push_back(userData);
            }
        }
    }
}

void UsersData::storeData(){
     QString path = QString::fromStdString(addData.usersDataPath);
    QJsonArray users;
    for(int i = 0; i < addData.usersList.size(); i++){
        int sid;
        int points;
        double bank;
        string sname;
        string spass;
        string slea ;

        // if(i == userData.userIndex){
        //     QJsonObject user;

        //     sid = userData.currentUserData.id;
        //     bank = userData.currentUserData.bank;
        //     sname = userData.currentUserData.name;
        //     spass = userData.currentUserData.password;
        //     slea = userData.currentUserData.league;

        //     user["id"] =  sid;
        //     user["name"] =  sname.data();
        //     user["password"] =  spass.data();
        //     user["league"] =  slea.data();
        //     user["bank"] = bank;

        //     users.append(user);
        //     continue;
        // }
        QJsonObject user;

        sid = addData.usersList[i].id;
        bank = addData.usersList[i].bank;
        sname = addData.usersList[i].name;
        spass = addData.usersList[i].password;
        slea = addData.usersList[i].league;
        points=addData.usersList[i].points;



        user["id"] =  sid;
        user["name"] =  sname.data();
        user["password"] =  spass.data();
        user["league"] =  slea.data();
        user["bank"] = bank;
        user["points"]=points;

        users.append(user);

    }

    QJsonDocument doc(users);
    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
    }
}

