#include "team.h"
#include <unordered_map>
Team::Team() {}


Team::Team(int tId, string na , string leg){
    id = tId ;
    name = na;
    league = leg;
    unordered_map<int,Player> players;
}
