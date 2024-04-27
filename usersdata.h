#ifndef USERSDATA_H
#define USERSDATA_H
#include<QtSql/QtSql>

class UsersData
{
public:
    UsersData();
    QSqlDatabase Qt_connection;

    void loadData();
    void storeData();
};


#endif // USERSDATA_H
