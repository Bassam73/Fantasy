#ifndef USERSDATA_H
#define USERSDATA_H
#include<QtSql/QtSql>

class UsersData
{
public:
    UsersData();
    QSqlDatabase Qt_connection;
    void dataBase();
    void fetchData();

};


#endif // USERSDATA_H
