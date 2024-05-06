#include "user.h"
#include "admin.h"
#include <MyProfileGui.h>
#include <QString>
#include <regex>

User::User(int i , string u , string p , string l)
{
    id = i;
    name = u ;
    password = p;
    league = l;
}
User::User(){}
    Admin adminn;


bool User::registerUser(){
    const regex userPattern("^[A-Z][a-z]{2,}$");
    const regex passPattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");
    if(!regex_match(name,userPattern))return false;
    bool nameCheck= checkUsername(name);
    bool passCheck = regex_match(password, passPattern);
    cout << passCheck;

    Admin registerAdmin;

    if  (nameCheck == false || passCheck==false) return false;

    User registeredUser(id ,name , password , league);
    registerAdmin.usersList.push_back(registeredUser);
    currentUserData = registeredUser;
    qDebug() << currentUserData.name;
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
            qDebug()<<currentUserData.name;
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

int User::getPlayerData(int id, float &cost, string &team, string &position, string &name, int high, int low, vector<Player>& playersList){

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
};
