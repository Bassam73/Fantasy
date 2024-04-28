#ifndef TEAM_H
#define TEAM_H
#include "player.h"
#include <unordered_map>
class Team
{
public:
    string name;
    int id ;
    int position;
    int points;
    unordered_map<int,Player> teamPlayers;
    Team();
    Team(int , string);
};

#endif // TEAM_H
