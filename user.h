#ifndef USER_H
#define USER_H

#include <QString>
#include <iostream>
#include "player.h"
#include <set>

using namespace std;
class User
{
public:
    int id;
    double bank;
    int points;
    string name ;
    string password;
    string league;
    multiset<pair<int,string>> plPlayersStandings;
    multiset<pair<int,string>> laLigaPlayersStandings;

    multiset<pair<int,string>> goalsStats;
    multiset<pair<int,string>> assistsStats;
    multiset<pair<int,string>> yellowCardStats;
    multiset<pair<int,string>> cleanSheetsStats;
    bool luckyWheelUsed;


    map<int,int>userGwPoints;


    User(int ,int, string , string , string , double );
    User(int ,int, string , string , string , double , bool , map<int,int>);
    User(int ,int, string , string , string , double , bool);

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
    QString  standings();

    QString  stats(string);

};


#endif // USER_H
