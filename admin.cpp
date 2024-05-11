#include "admin.h"
#include "qdebug.h"

#include <Math.h>


vector<Team> Admin::plTeamsList;
vector<Team> Admin::ligaTeamsList;
int Admin::GAME_WEEK=1;


// unordered_map<string, vector<Player>> Admin::teamPlayers;

string playerRedCarded;
vector<string> redCardPlayers;
vector<string> mins60PlusPlayers;
vector<string> cleanCheatPlayers;
vector<string> yellowCardsPlayers;
vector<string> raisedPricePlayers;
vector<string> reducedPricePlayers;


string Admin::playersDataPath = "C:/Users/pc/Documents/FantasyProject/Fantasy/dataOfPlayers.json";
string Admin::teamsDataPath = "C:/Users/pc/Documents/FantasyProject/Fantasy/dataOfTeams.json";
string Admin::usersDataPath = "C:/Users/pc/Documents/FantasyProject/Fantasy/dataOfUser.json";
string Admin::plPlayersDataPath = "C:/Users/pc/Documents/FantasyProject/Fantasy/PLplayers.json";
string Admin::gameWeeksDataPath = "C:/Users/pc/Documents/FantasyProject/Fantasy/dataOfGameWeeks.json";
string Admin::UsersDataInGamePath = "C:/Users/pc/Documents/FantasyProject/Fantasy/dataOfuserAccount.json";
bool mins = true;
bool cs = true;
bool redCard = true;


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

int Admin::addPlayer(string name, string position, string team, int age, int kitnum , float playerCost) {

    int id;
    Player newPlayer;





    if (playersList.empty()) {
        id = 1;
    } else {
        int x = playersList.size();
        id = playersList[x - 1].id + 1;
    }

    newPlayer.id = id;
    newPlayer.age = age;
    newPlayer.name = name;
    newPlayer.team = team;
    newPlayer.kitNumber = kitnum;
    newPlayer.position = position;
    newPlayer.cost = playerCost;
    newPlayer.goals =0;
    newPlayer.assists = 0;
    newPlayer.cleanSheets = 0 ;
    newPlayer.yellowCards= 0;
    newPlayer.points= 0;

    playersList.push_back(newPlayer);
    teamPlayers[team].push_back(newPlayer);
    return 0;
}

int Admin::deletePlayer(vector<Player>& playersList,int low,int high,int PlayerID){

    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (playersList[mid].id == PlayerID){
            string squad = playersList[mid].team;

            playersList.erase(playersList.begin() + mid );
            qDebug() << mid;
            for(auto it = teamPlayers[squad].begin(); it < teamPlayers[squad].end(); it++){
                if((*it).id == PlayerID){
                    teamPlayers[squad].erase(it);
                    qDebug() << "hola";
                    qDebug() << (*it).name;
                    break;
                }
            }


            return 1;
        }

        if (playersList[mid].id > PlayerID)
            return deletePlayer(playersList, low, mid - 1, PlayerID);

        return deletePlayer(playersList, mid + 1, high, PlayerID);
    }

    return -1;
}


int Admin::updatePlayers(vector<Player>& playersList,int low,int high,int PlayerID,int age,int kitNumber,string position){

    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (playersList[mid].id == PlayerID){

             string squad = playersList[mid].team;

            if(age==0||kitNumber==0||position.empty()){
                playersList[mid].age=playersList[mid].age;
                playersList[mid].kitNumber=playersList[mid].kitNumber;
                playersList[mid].position=playersList[mid].position;

            }
            else{
                playersList[mid].age=age;
                playersList[mid].kitNumber=kitNumber;
                playersList[mid].position=position;


                for(auto it = teamPlayers[squad].begin(); it < teamPlayers[squad].end(); it++){
                    if((*it).id == PlayerID){
                        teamPlayers[squad].data()->age=age;
                        teamPlayers[squad].data()->kitNumber=kitNumber;
                        teamPlayers[squad].data()->position=position;

                        qDebug() << teamPlayers[squad].data()->position;
                        break;
                    }
                }
            }




            return 1;
        }

        if (playersList[mid].id > PlayerID)
            return updatePlayers(playersList, low, mid - 1, PlayerID, age, kitNumber, position);

        return updatePlayers(playersList, mid + 1, high, PlayerID, age, kitNumber, position);
    }

    return -1;
}
int Admin::addPoints(string playerName, QString action) {
    auto playerIt = std::find_if(playersList.begin(), playersList.end(),
                                 [&](const Player& player) { return player.name == playerName; });

    if (playerIt != playersList.end()) {
        for (int i = 0; i < redCardPlayers.size(); i++) {
            if (redCardPlayers[i] == playerIt->name) {
                return 1;
            }
        }

        for (int i = 0; i < mins60PlusPlayers.size(); i++) {
            if (mins60PlusPlayers[i] == playerIt->name && action == "60+ min") {
                return 2;
            }
        }

        for (int i = 0; i < cleanCheatPlayers.size(); i++) {
            if (cleanCheatPlayers[i] == playerIt->name && action == "Clean Sheet") {
                return 3;
            }
        }

        for (int i = 0; i < yellowCardsPlayers.size(); i++) {
            if (yellowCardsPlayers[i] == playerIt->name && action == "Yellow Card") {
                playerIt->gwPoints[GAME_WEEK] -= 1;
                playerIt->yellowCards++;
                action = "Red Card";
            }
        }

        if (action == "60+ min") {
            playerIt->gwPoints[GAME_WEEK] += 2;
            mins60PlusPlayers.push_back(playerIt->name);
        } else if (action == "Assist") {
            playerIt->gwPoints[GAME_WEEK] += 3;
            playerIt->assists++;

        }
        else if (action == "Penality Missed") {
            playerIt->gwPoints[GAME_WEEK] -= 3;
        }

        else if (action == "Red Card") {
            redCard = true;
            playerRedCarded = playerIt->name;
            playerIt->gwPoints[GAME_WEEK] -= 3;
            redCardPlayers.push_back(playerRedCarded);
        } else if (action == "Yellow Card") {
            yellowCardsPlayers.push_back(playerIt->name);
            playerIt->gwPoints[GAME_WEEK] -= 1;
            playerIt->yellowCards++;
        } else if (playerIt->position == "GK" || playerIt->position == "DEF") {
            if (action == "Goal") {
                playerIt->gwPoints[GAME_WEEK] += 6;
                playerIt->goals++;
            } else if (action == "Clean Sheet") {
                cleanCheatPlayers.push_back(playerIt->name);
                playerIt->gwPoints[GAME_WEEK] += 4;

                if(playerIt->position == "GK"){
                 playerIt->cleanSheets++;
                }

            }
        } else if (playerIt->position == "MID") {
            if (action == "Goal") {
                playerIt->gwPoints[GAME_WEEK] += 5;
                 playerIt->goals++;
            } else if (action == "Clean Sheet") {
                cleanCheatPlayers.push_back(playerIt->name);
                playerIt->gwPoints[GAME_WEEK] += 1;
            }
        } else if (playerIt->position == "ATT" && action == "Goal") {
            playerIt->gwPoints[GAME_WEEK] += 4;
             playerIt->goals++;
        }

        int totalPoints = 0;
        for (int i = 0; i < 18; ++i) {
            totalPoints += playerIt->gwPoints[i];
        }
        playerIt->points = totalPoints;

        if (playerIt->points >= 10) {
            bool costRaised = std::find(raisedPricePlayers.begin(), raisedPricePlayers.end(), playerIt->name) != raisedPricePlayers.end();

            if (!costRaised) {
                raisedPricePlayers.push_back(playerIt->name);
                playerIt->cost += 0.1;
            }
        }
        if (playerIt->points <=0) {
            bool costReduced = std::find(reducedPricePlayers.begin(), reducedPricePlayers.end(), playerIt->name) != reducedPricePlayers.end();

            if (!costReduced) {
                reducedPricePlayers.push_back(playerIt->name);
                playerIt->cost -= 0.1;
            }
        }
    }
    cout <<playerIt->goals<<endl;
    cout <<playerIt->assists<<endl;
    cout <<playerIt->yellowCards<<endl;
    cout <<playerIt->cleanSheets<<endl;

    return 0;
}




void Admin::nextGameWeek(){

  GAME_WEEK++;

    redCardPlayers.clear();
    mins60PlusPlayers.clear();
    cleanCheatPlayers.clear();
    yellowCardsPlayers.clear();
    reducedPricePlayers.clear();
    raisedPricePlayers.clear();

     mins = true;
     cs = true;
     redCard = true;
 }


 void Admin::luckyWheel(){
     int DEFS =0;
     int MIDS = 0 ;
     int ATTS=0;

     cout << "We Are Here" ;
     if(!User::currentUserData.luckyWheelUsed){

         int randomId = rand() % playersList.size();
         cout << randomId;
         bool leagueCheck = false;
         if(User::currentUserData.league == "Premier League"){
             for(auto team : plTeamsList){
                 if(playersList[randomId].team == team.name){
                     leagueCheck= true ;
                     break;
                 }
             }
         }
         else {
             for(auto team : ligaTeamsList){
                 if(playersList[randomId].team == team.name){
                     leagueCheck= true ;
                     break;
                 }
             }}

         if(leagueCheck){

             auto playerIt=  User::currentUserData.usersTeam.find(playersList[randomId].name);
            if(playerIt == User::currentUserData.usersTeam.end()){

             if(playersList[randomId].cost > 0){

                for(auto i :User::currentUserData.usersTeam){
                     if(i.second.position == "DEF"){
                        DEFS++;
                    }
                     else if(i.second.position == "MID"){
                         MIDS++;
                     }
                     else if(i.second.position == "ATT"){
                         ATTS++;
                     }
                 }

                if(playersList[randomId].position=="ATT"&&ATTS>=3){
                     Admin::luckyWheel();
                 }
                if(playersList[randomId].position=="DEF"&&DEFS>=4){
                    Admin::luckyWheel();
                }
                if(playersList[randomId].position=="MID"&&DEFS>=3){
                    Admin::luckyWheel();
                }
                User::currentUserData.usersTeam[playersList[randomId].name] = playersList[randomId];
                User::currentUserData.luckyWheelUsed = true ;
            }
             else{
                  Admin::luckyWheel();
             }
         }
         }
         else{
              Admin::luckyWheel();
         }

     }

     else {
         return;
     }
 };
