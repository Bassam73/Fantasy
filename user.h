#ifndef USER_H
#define USER_H

#include <QString>
#include <iostream>
#include "player.h"
using namespace std;
class User
{
public:
    int id;
    double bank;
    string name ;
    string password;
    string league;
    User(int , string , string , string , double );
    User();
    static string CURRENTPOS;
    static map <int, vector<string>> userPlayers;
    static map <string, Player> usersTeam;
    static int userIndex;
    static bool checkRegisteredUser(string, string);
    static User currentUserData;
    static int currentUserId;

    bool registerUser();
    bool checkUsername(string );
    bool isValidPassword(string);

    int forgetPassword (string,string,string);

    int getPlayerData(int id, double &cost, string &team, string &position, string &name, int high, int low, vector<Player> &playersList);

    string posFilter(QString, QString);
    QStringList getTeams();
    QStringList getPlayers();
    QStringList filterPlayersByTeam(QString);
    QStringList filterPlayersByCost(QString,QString);


    void bankHandling(QString playerName);
};


#endif // USER_H
