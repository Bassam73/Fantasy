#include "admin.h"

vector<Team> Admin::teamsList;
Admin::Admin() {}



void Admin::addTeams( string name , string league ){

    int id ;
    if(teamsList.empty()){
        id = 1 ;
    }else{
        int x = teamsList.size();
        id = teamsList[x-1].id +1;
    }

    Team newTeam(id , name ,league);
    teamsList.push_back(newTeam);
}

