#ifndef TEAM_H
#define TEAM_H
#include "player.h"
#include <unordered_map>
#include <vector>
#include <QString>
class Team
{
public:
    string name;
    int id ;
    int position;
    string league;
    int points;
    // unordered_map<int,Player> teamPlayers;

    Team();
    Team(int , string,string);
    void savePlayers(vector<QString> players);
    void calculatePoints();
};

#endif // TEAM_H
