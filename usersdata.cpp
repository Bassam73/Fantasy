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
            bool luckyWheel;


            for(auto i:arr){
                user = i.toObject();
                id = user.value("id").toInt();
                userName = user.value("name").toString();
                password = user.value("password").toString();
                league = user.value("league").toString();
                bank = user.value("bank").toDouble();
                points=user.value("points").toInt();
                luckyWheel = user.value("luckyWheel").toBool();
                // if (bank == NULL){
                //     bank = 100;
                // }

                name = userName.toStdString();
                pass = password.toStdString();
                leag = league.toStdString();

                User userData(id ,points, name, pass, leag, bank,luckyWheel);

                addData.usersList.push_back(userData);
            }
        }
    }
}

void UsersData::storeData(){

     QString path = QString::fromStdString(addData.usersDataPath);
    QJsonArray users;
    for(int i = 0; i < addData.usersList.size(); i++){
        if(addData.usersList[i].name == User::currentUserData.name){
            addData.usersList[i].luckyWheelUsed = User::currentUserData.luckyWheelUsed;
        }
        int sid;
        int points;
        double bank;
        string sname;
        string spass;
        string slea ;
        QJsonObject user;
        bool sLucky;

        sid = addData.usersList[i].id;
        bank = addData.usersList[i].bank;
        sname = addData.usersList[i].name;
        spass = addData.usersList[i].password;
        slea = addData.usersList[i].league;
        points=addData.usersList[i].points;
        sLucky = addData.usersList[i].luckyWheelUsed;


        user["id"] =  sid;
        user["name"] =  sname.data();
        user["password"] =  spass.data();
        user["league"] =  slea.data();
        user["bank"] = bank;
        user["points"]=points;
        user["luckyWheel"] = sLucky;
        users.append(user);

    }

    QJsonDocument doc(users);
    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
    }
}

