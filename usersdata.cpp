#include "usersdata.h"
#include <QString>

#include <iostream>
using namespace std;


UsersData::UsersData() {

}
void UsersData::dataBase(){
    //database connection

    // Qt_connection =QSqlDatabase::addDatabase("QSQLITE");
    // Qt_connection.setDatabaseName(QCoreApplication::applicationDirPath()+"userData.db");
    // if(Qt_connection.open()){
    //     qDebug()<<"is open";
    // }
    // else{
    //     qDebug()<<"is not open";

    // }
}

void UsersData::fetchData(){
    Qt_connection =QSqlDatabase::addDatabase("QSQLITE");
    Qt_connection.setDatabaseName(QCoreApplication::applicationDirPath()+"/userData.db");
    qDebug()<<QCoreApplication::applicationDirPath();
    Qt_connection.open();
    if(Qt_connection.open()){
        qDebug()<<"is open";
    }
    else{
        qDebug()<<"is not open";

    }

    QSqlDatabase::database().transaction();
    QSqlQuery loadData(Qt_connection);





    loadData.prepare("INSERT INTO UsersData(id,username,passwoed,league) VALUES (:id,:username,:passwoed,:league)");
    loadData.bindValue(":id",2);
    loadData.bindValue(":username","coco");
    loadData.bindValue(":passwoed","4321");
    loadData.bindValue(":league","pl");
    loadData.exec();
    QSqlDatabase::database().commit();

    // if(QSqlDatabase::database().commit()){
    //     qDebug()<<"it works";
    // }
    // else {
    //        qDebug()<<"nope";

    // }

   // loadData.prepare("SELECT username FROM UsersData");

    QVariant singleValue;
    if(loadData.exec("SELECT * FROM UsersData")){
        while(loadData.next()){
        qDebug()<<loadData.value(1).toString();
            singleValue = loadData.value(1);
        }
    }
    else{
        qDebug()<<loadData.lastError().text();
    }
   // qDebug()<<singleValue.toString();
    QString uname = singleValue.toString();
    uname.toStdString();
  //  qDebug()<<uname;
    Qt_connection.close();

}
