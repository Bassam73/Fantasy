#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <vector>
#include <map>
#include <unordered_map>
#include "player.h"
#include "admin.h"
#include "user.h"
#include "registergui.h"
#include "usersdata.h"
#include "teamdata.h"
#include "playerdata.h"
#include "player.h"
#include "gameweeksdata.h"
#include "userdataingame.h"
#include "user.h"

vector<User> Admin::usersList;
User User::currentUserData;
unordered_map<string, vector<Player>> Admin::teamPlayers;
vector<Player> Admin::playersList;
map <int, vector<int>> User::userPlayers;

Admin add;
User use;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "FantasyProject_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    GameWeeksData gw ;
    gw.loadData();

    UsersData data;
    data.loadData();

    TeamData teams;
    teams.loadData();

    PlayerData playerData;
    playerData.loadData();

    userDataInGame gameData;
    gameData.loadData();


    User::userPlayers[5].push_back(7);

    for(auto i = User::userPlayers.begin(); i != User::userPlayers.end(); i++){
        qDebug() << i->first;
        for(auto j:i->second){
            qDebug() << j;
        }
    }
    RegisterGui w;
    w.show();

    int returnValue = a.exec();
    teams.storeData();
    data.storeData();
    gw.storeData();
    playerData.storeData();
    gameData.storeData();
    return returnValue;
}
