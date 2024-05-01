#include "usersdata.h"
#include <QString>
#include "admin.h"
#include "user.h"
#include <vector>
using namespace std;
Admin addData;


UsersData::UsersData()
{

}

void UsersData::loadData(){
    QFile file("C:/Users/besho/Fantasy/dataOfUser.json");
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

                name = userName.toStdString();
                pass = password.toStdString();
                leag = league.toStdString();

                User userData(id , name, pass, leag);

                addData.usersList.push_back(userData);
            }
        }
    }
}

void UsersData::storeData(){

    QJsonArray users;
    for(int i = 0; i < addData.usersList.size(); i++){

        QJsonObject user;

        int sid = addData.usersList[i].id;
        string sname = addData.usersList[i].name;
        string spass = addData.usersList[i].password;
        string slea = addData.usersList[i].league;


        user["id"] =  sid;
        user["name"] =  sname.data();
        user["password"] =  spass.data();
        user["league"] =  slea.data();

        users.append(user);

    }

    QJsonDocument doc(users);
    QFile file("C:/Users/besho/Fantasy/dataOfUser.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
    }
}

