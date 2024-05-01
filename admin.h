#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <unordered_map>
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
    static int GAME_WEEK;
    static unordered_map<string, vector<Player>> teamPlayers;

    Admin();
    bool addTeams(string,string);
    bool deleteTeam(string , string);
    int addPlayer( string, string, string, string, int, int);
    int deletePlayer(vector<Player>&,int,int,int);
    int addPoints(string ,QString);
    void nextGameWeek();
};




#endif // ADMIN_H
