#ifndef USERDATAINGAME_H
#define USERDATAINGAME_H
#include<QtSql/QtSql>
class userDataInGame
{
public:
    userDataInGame();
    QSqlDatabase Qt_connection;

    void loadData();
    void storeData();
};

#endif // USERDATAINGAME_H
