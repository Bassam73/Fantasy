#include "team.h"
#include "user.h"
#include "admin.h"
#include <unordered_map>
Team::Team() {}


Team::Team(int tId, string na , string leg){
    id = tId ;
    name = na;
    league = leg;
    unordered_map<int,Player> players;
}
void Team::savePlayers(vector<QString> players){
    for(auto i:players){
        for(auto j:Admin::playersList){
            if(i.toStdString() == j.name){
                User::usersTeam[i.toStdString()] = j;
                User::userPlayers[User::currentUserData.id].push_back(i.toStdString());
            }
        }
    }
}
void Team::calculatePoints(){
    // User::currentUserData.points=0;
    // for(auto i=User::usersTeam.begin();i!=User::usersTeam.end();i++){
    //     User::currentUserData.points +=i->second.points;
    // }
    // Admin::usersList[User::userIndex].points=User::currentUserData.points;

    User::currentUserData.userGwPoints[Admin::GAME_WEEK] = 0 ;

    for(auto i=User::usersTeam.begin();i!=User::usersTeam.end();i++){
        User::currentUserData.userGwPoints[Admin::GAME_WEEK] += i->second.gwPoints[Admin::GAME_WEEK];
    }

    User::currentUserData.points+= User::currentUserData.userGwPoints[Admin::GAME_WEEK];

    Admin::usersList[User::userIndex].userGwPoints[Admin::GAME_WEEK]=User::currentUserData.userGwPoints[Admin::GAME_WEEK];
    Admin::usersList[User::userIndex].points=User::currentUserData.points;



}
