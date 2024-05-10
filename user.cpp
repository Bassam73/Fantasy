#include "user.h"
#include "admin.h"
#include <MyProfileGui.h>
#include <QString>
#include <regex>
#include <set>

User::User(int i ,int point, string u , string p , string l, double ban)
{
    id = i;
    points=point;
    name = u ;
    password = p;
    league = l;
    bank = ban;
}
User::User(){}
    Admin adminn;
User::User(int i ,int point, string u , string p , string l, double ban , bool wheel){
    id = i;
    points=point;
    name = u ;
    password = p;
    league = l;
    bank = ban;
    luckyWheelUsed = wheel;
}

bool User::registerUser(){
    const regex userPattern("^[A-Z][a-z]{2,}$");
    const regex passPattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");
    if(!regex_match(name,userPattern))return false;
    bool nameCheck= checkUsername(name);
    bool passCheck = regex_match(password, passPattern);
    cout << passCheck;

    Admin registerAdmin;

    if  (nameCheck == false || passCheck==false) return false;

    User registeredUser(id ,points ,name , password , league, bank);
    registerAdmin.usersList.push_back(registeredUser);

    userIndex = registerAdmin.usersList.size() - 1;

    qDebug()<<userIndex;

    currentUserData = registeredUser;
    for(int i = 0; i < User::userPlayers[User::currentUserData.id].size(); i++){

        for(auto j:Admin::playersList){
            string name = User::userPlayers[User::currentUserData.id][i];
            if(name == j.name){
                User::usersTeam[name] = j;
            }
        }
    }


    qDebug() << currentUserData.name;
    qDebug()<<currentUserData.bank;
    qDebug() << usersTeam.size();
    Team playersPoints;
    playersPoints.calculatePoints();
    User players;
    players.standings();
    return true;
}




bool User::checkUsername(string username){
    cout <<"We ARE IN CHECK USER"<<endl;
    Admin mainAdmin ;

    if (mainAdmin.usersList.empty()) {
        return true;
    }
    for(int i = 0 ; i < mainAdmin.usersList.size();i++){
        if(mainAdmin.usersList[i].name == username){
            return false;
        }
    }

    return true;
}
bool User::checkRegisteredUser(string name ,string password){
    Admin login;

    for(int i=0;i<login.usersList.size();i++){
        if(login.usersList[i].name==name&&
            login.usersList[i].password==password){
            currentUserData.id=login.usersList[i].id;
            currentUserData.name=login.usersList[i].name;
            currentUserData.password=login.usersList[i].password;
            currentUserData.league=login.usersList[i].league;
            currentUserData.bank = login.usersList[i].bank;
            currentUserData.points=login.usersList[i].points;
            currentUserData.luckyWheelUsed= login.usersList[i].luckyWheelUsed;

            userIndex = i;

            for(int i = 0; i < User::userPlayers[User::currentUserData.id].size(); i++){

                for(auto j:Admin::playersList){
                    string name = User::userPlayers[User::currentUserData.id][i];
                    if(name == j.name){
                        User::usersTeam[name] = j;
                    }
                }
            }

            qDebug()<<currentUserData.bank;
            qDebug() << usersTeam.size();
            Team playersPoints;
            playersPoints.calculatePoints();
            User players;
            players.standings();
            return true;
        }

    }
    return false;
}
int User::forgetPassword(string username,string newPassword,string reNewPassword){
    bool isFound=false;
    bool passCheck;
    int i;
    for(i=0;i<Admin::usersList.size();i++){
        if(Admin::usersList[i].name==username){
            isFound=true;
            break;
        }
    }
    if(!isFound){
        return 1;
    }
    else{
        const regex passPattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");
        passCheck = regex_match(newPassword, passPattern);
        if(!passCheck){
            return 2;
        }
    }
    if(reNewPassword!=newPassword){
        return 3;
    }
    Admin::usersList[i].password=newPassword;
    return 4;

}

int User::getPlayerData(int id, double &cost, string &team, string &position, string &name, int high, int low, vector<Player>& playersList){

    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (playersList[mid].id == id){
            // code


        }

        if (playersList[mid].id > id)
            return getPlayerData(id, cost, team, position, name,low, mid - 1, playersList);

        return getPlayerData(id, cost, team, position, name, mid + 1, high, playersList);
    }

}



QStringList User::getTeams(){

    QStringList teamNames;
    teamNames<<"All Teams";
    if(currentUserData.league == "Premier League"){

        for(auto team : adminn.plTeamsList){
            teamNames << team.name.data() ;
        }
    }else{
        for(auto team : adminn.ligaTeamsList){
            teamNames << team.name.data() ;
        }
    }
    return teamNames;
}



QStringList User::getPlayers(){
    QStringList teams;
    if(currentUserData.league =="Premier League"){
    for(auto player : adminn.playersList){

            bool check = false ;
            for(auto team : adminn.plTeamsList){
                if(team.name == player.team){
                    check = true;
                    break;
                }
            }
            if(player.position.data() == User::CURRENTPOS && check){

            QString playerName=  QString::fromStdString(player.name);
            double playerCost=  player.cost;
            QString playerTeam=  QString::fromStdString(player.team);
            double playerPoints=  player.points;
            QString playerInfo = playerName + " (" + playerTeam + ") (Cost: $" + QString::number(playerCost, 'f', 2) + " Points : " + QString::number(playerPoints, 'f', 0)+ ")";

            teams<<playerInfo;
        }

        }
    }
    else{
        for(auto player : adminn.playersList){

            bool check = false ;
            for(auto team : adminn.ligaTeamsList){
                if(team.name == player.team){
                    check = true;
                    break;
                }
            }
            if(player.position.data() == User::CURRENTPOS && check){

                QString playerName=  QString::fromStdString(player.name);
                double playerCost=  player.cost;
                QString playerTeam=  QString::fromStdString(player.team);
                double playerPoints=  player.points;
                QString playerInfo = playerName + " (" + playerTeam + ") (Cost: $" + QString::number(playerCost, 'f', 2) + " Points : " + QString::number(playerPoints, 'f', 0)+ ")";

                teams<<playerInfo;
            }

        }

    }
            return teams;
    }
QStringList User::filterPlayersByTeam(QString teamName){
    QStringList teams;
    if(currentUserData.league =="Premier League"){
        for(auto player : adminn.playersList){

            bool check = false ;
            for(auto team : adminn.plTeamsList){
                if(team.name == player.team){
                    check = true;
                    break;
                }
            }
            if(player.position.data() == User::CURRENTPOS && check && player.team.data() == teamName){

                QString playerName=  QString::fromStdString(player.name);
                double playerCost=  player.cost;
                QString playerTeam=  QString::fromStdString(player.team);

                double playerPoints=  player.points;
                QString playerInfo = playerName + " (" + playerTeam + ") (Cost: $" + QString::number(playerCost, 'f', 2) + " Points : " + QString::number(playerPoints, 'f', 0)+ ")";

                teams<<playerInfo;
            }

        }
    }
    else{
        for(auto player : adminn.playersList){

            bool check = false ;
            for(auto team : adminn.ligaTeamsList){
                if(team.name == player.team){
                    check = true;
                    break;
                }
            }
            if(player.position.data() == User::CURRENTPOS && check&& player.team.data() == teamName){

                QString playerName=  QString::fromStdString(player.name);
                double playerCost=  player.cost;
                QString playerTeam=  QString::fromStdString(player.team);
                double playerPoints=  player.points;
                QString playerInfo = playerName + " (" + playerTeam + ") (Cost: $" + QString::number(playerCost, 'f', 2) + " Points : " + QString::number(playerPoints, 'f', 0)+ ")";

                teams<<playerInfo;
            }

        }

    }
    return teams;
}


QStringList User::filterPlayersByCost(QString costFilter,QString selectedTeam){
    double maxCost = numeric_limits<double>::infinity();
    if (costFilter != "Unlimited") {
        maxCost = costFilter.toDouble();
    }
    QStringList teams;
    if(currentUserData.league =="Premier League"){
        for(auto player : adminn.playersList){

            bool check = false ;
            for(auto team : adminn.plTeamsList){
                if(team.name == player.team){
                    check = true;
                    break;
                }
            }
            if(player.position == User::CURRENTPOS && (player.team.data() == selectedTeam ||selectedTeam == "All Teams") && player.cost<=maxCost&&check){

                QString playerName=  QString::fromStdString(player.name);
                double playerCost=  player.cost;
                QString playerTeam=  QString::fromStdString(player.team);
                double playerPoints=  player.points;
                QString playerInfo = playerName + " (" + playerTeam + ") (Cost: $" + QString::number(playerCost, 'f', 2) + " Points : " + QString::number(playerPoints, 'f', 0)+ ")";
                teams<<playerInfo;
            }

        }
    }
    else{
        for(auto player : adminn.playersList){

            bool check = false ;
            for(auto team : adminn.ligaTeamsList){
                if(team.name == player.team){
                    check = true;
                    break;
                }
            }
            if(player.position == User::CURRENTPOS && (player.team.data() == selectedTeam ||selectedTeam == "All Teams") && player.cost<=maxCost&&check){

                QString playerName=  QString::fromStdString(player.name);
                double playerCost=  player.cost;
                QString playerTeam=  QString::fromStdString(player.team);
                double playerPoints = player.points;
                QString playerInfo = playerName + " (" + playerTeam + ") (Cost: $" + QString::number(playerCost, 'f', 2) + " Points : " + QString::number(playerPoints, 'f', 0)+ ")";
                teams<<playerInfo;
            }

        }

    }
    return teams;
}

void User::bankHandling(QString playerName){
    for(auto i = Admin::playersList.begin(); i != Admin::playersList.end(); i++){
        if(i->name == playerName.toStdString()){
            User::currentUserData.bank += i->cost;
        }
    }
}

QString User::standings() {
    QString standingsText;
    for (auto i : Admin::usersList) {
        if(i.league == "Premier League")
        plPlayersStandings.insert(make_pair(i.points, i.name));
        else {
            laLigaPlayersStandings.insert(make_pair(i.points , i.name));
        }
    }
    multiset<pair<int, string>>::reverse_iterator j;
    if(User::currentUserData.league == "Premier League"){
        for (j = plPlayersStandings.rbegin(); j != plPlayersStandings.rend(); j++) {
            standingsText.append(QString::number(j->first) + " " + QString::fromStdString(j->second) + "\n");
        }
    }

    else{
        for (j = laLigaPlayersStandings.rbegin(); j != laLigaPlayersStandings.rend(); j++) {
            standingsText.append(QString::number(j->first) + " " + QString::fromStdString(j->second) + "\n");
        }
    }
    return standingsText;
}





QString User::stats(string stat) {
    QString statsText;

    if (User::currentUserData.league == "Premier League") {
        for (auto player : Admin::playersList) {
            for (int i = 0; i < Admin::plTeamsList.size(); i++) {
                if (player.team == Admin::plTeamsList[i].name) {
                    if (stat == "Goals" && player.goals != 0) {
                        goalsStats.insert(make_pair(player.goals, player.name));
                    } else if (stat == "Assists" && player.assists != 0) {
                        assistsStats.insert(make_pair(player.assists, player.name));
                    } else if (stat == "Yellow Cards" && player.yellowCards != 0) {
                        yellowCardStats.insert(make_pair(player.yellowCards, player.name));
                    } else if (stat == "Clean Sheets" && player.cleanSheets != 0) {
                        cleanSheetsStats.insert(make_pair(player.cleanSheets, player.name));
                    }
                }
            }
        }
    } else {
        for (auto player : Admin::playersList) {
            for (int i = 0; i < Admin::ligaTeamsList.size(); i++) {
                if (player.team == Admin::ligaTeamsList[i].name) {
                    if (stat == "Goals" && player.goals != 0) {
                        goalsStats.insert(make_pair(player.goals, player.name));
                    } else if (stat == "Assists" && player.assists != 0) {
                        assistsStats.insert(make_pair(player.assists, player.name));
                    } else if (stat == "Yellow Cards" && player.yellowCards != 0) {
                        yellowCardStats.insert(make_pair(player.yellowCards, player.name));
                    } else if (stat == "Clean Sheets" && player.cleanSheets != 0) {
                        cleanSheetsStats.insert(make_pair(player.cleanSheets, player.name));
                    }
                }
            }
        }
    }

    multiset<pair<int, string>>::reverse_iterator j;

    if (stat == "Goals") {
        for (j = goalsStats.rbegin(); j != goalsStats.rend(); j++) {
            statsText.append(QString::number(j->first) + " " + QString::fromStdString(j->second) + "\n");
        }
    } else if (stat == "Assists") {
        for (j = assistsStats.rbegin(); j != assistsStats.rend(); j++) {
            statsText.append(QString::number(j->first) + " " + QString::fromStdString(j->second) + "\n");
        }
    } else if (stat == "Clean Sheets") {
        for (j = cleanSheetsStats.rbegin(); j != cleanSheetsStats.rend(); j++) {
            statsText.append(QString::number(j->first) + " " + QString::fromStdString(j->second) + "\n");
        }
    } else if (stat == "Yellow Cards") {
        for (j = yellowCardStats.rbegin(); j != yellowCardStats.rend(); j++) {
            statsText.append(QString::number(j->first) + " " + QString::fromStdString(j->second) + "\n");
        }
    }

    goalsStats.clear();
    assistsStats.clear();
    cleanSheetsStats.clear();
    yellowCardStats.clear();

    return statsText;
}
