#include "admin.h"
#include "qdebug.h"

vector<Team> Admin::plTeamsList;
vector<Team> Admin::ligaTeamsList;
// unordered_map<string, vector<Player>> Admin::teamPlayers;


Admin::Admin() {}



bool Admin::addTeams(string name, string league) {

    Team newTeam;

    if (league == "LaLiga") {
        int id;
        if (ligaTeamsList.empty()) {
            id = 1;
        } else {
            int x = ligaTeamsList.size();
            id = ligaTeamsList[x - 1].id + 1;
        }

        for (int i = 0; i < ligaTeamsList.size(); i++) {
            if (name == ligaTeamsList[i].name) {
                return false;
            }
        }

        newTeam = Team(id, name, league);

        if (ligaTeamsList.size() == 10) {
            cout << "LaLiga full" << endl;
            return false;
        } else {
            ligaTeamsList.push_back(newTeam);
        }

    } else if (league == "Premier League") {
        int id;
        if (plTeamsList.empty()) {
            id = 1;
        } else {
            int x = plTeamsList.size();
            id = plTeamsList[x - 1].id + 1;
        }

        for (int i = 0; i < plTeamsList.size(); i++) {
            if (name == plTeamsList[i].name) {
                return false;
            }
        }

        newTeam = Team(id, name, league);

        if (plTeamsList.size() == 10) {
            cout << "Premier League full" << endl;
            return false;
        }

        plTeamsList.push_back(newTeam);

    }

    return true;
}


bool Admin::deleteTeam(string name ,string league){
    vector<Team>::iterator it ;
    if(league == "Premier League"){
        for(it= plTeamsList.begin() ; it!= plTeamsList.end() ; it++ ){
            if(name == it->name){
                plTeamsList.erase(it);
                return true;
            }
        }
    }
    else if(league == "LaLiga"){
        for(it= ligaTeamsList.begin() ; it!= ligaTeamsList.end() ; it++ ){
            if(name == it->name){
                ligaTeamsList.erase(it);
                return true;
            }
        }
    }

    return false;
}

int Admin::addPlayer(string name, string position, string team, string nation, int age, int kitnum) {

    int id;
    Player newPlayer;

    for(auto &it:teamPlayers[team]){
        if(kitnum > 99){
            return 1;
        }
        if(kitnum == it.kitNumber){
            return 2;
        }
    }



    if (playersList.empty()) {
        id = 1;
    } else {
        int x = playersList.size();
        id = playersList[x - 1].id + 1;
    }

    newPlayer.id = id;
    newPlayer.age = age;
    newPlayer.name = name;
    newPlayer.nationality = nation;
    newPlayer.team = team;
    newPlayer.kitNumber = kitnum;
    newPlayer.position = position;

    playersList.push_back(newPlayer);
    teamPlayers[team].push_back(newPlayer);
    return 0;
}

int Admin::deletePlayer(vector<Player>& playersList,int low,int high,int PlayerID){

    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (playersList[mid].id == PlayerID){
            playersList.erase(playersList.begin() + mid );


            return 1;
        }

        if (playersList[mid].id > PlayerID)
            return deletePlayer(playersList, low, mid - 1, PlayerID);

        return deletePlayer(playersList, mid + 1, high, PlayerID);
    }

    return -1;
}
