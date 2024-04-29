#include "admin.h"

vector<Team> Admin::plTeamsList;
vector<Team> Admin::ligaTeamsList;

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


