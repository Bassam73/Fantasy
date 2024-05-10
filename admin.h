#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include "user.h"
#include "team.h"
#include "player.h"

using namespace std;

class Admin
{
public:
    static vector<User> usersList;

    static vector<Team> plTeamsList;

    static vector<Team> ligaTeamsList;

    static vector <Player> playersList;




    static string playersDataPath;
    static string teamsDataPath;
    static string usersDataPath;
    static string plPlayersDataPath;
    static string gameWeeksDataPath;
    static string UsersDataInGamePath;


    static int GAME_WEEK;

    static unordered_map<string, vector<Player>> teamPlayers;

    Admin();
    bool addTeams(string,string);
    bool deleteTeam(string , string);
    int addPlayer( string, string, string, int, int, float);
    int deletePlayer(vector<Player>&,int,int,int);
    int updatePlayers(vector<Player>&,int,int,int,int,int,string);
    int addPoints(string ,QString);
    void nextGameWeek();
    void luckyWheel();
};




#endif // ADMIN_H
