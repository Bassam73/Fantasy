#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <vector>
#include <unordered_map>
#include "admin.h"
#include "user.h"
#include "registergui.h"
#include "usersdata.h"
#include "teamdata.h"
#include "playerdata.h"
#include "player.h"

vector<User> Admin::usersList;
User User::currentUserData;
unordered_map<string, vector<Player>> Admin::teamPlayers;
vector<Player> Admin::playersList;

Admin add;

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

    UsersData data;
    data.loadData();

    TeamData teams;
    teams.loadData();

    PlayerData playerData;
    playerData.loadData();

    RegisterGui w;
    w.show();

    qDebug() << add.teamPlayers.size();
    for(auto i = add.teamPlayers.begin(); i != add.teamPlayers.end(); i++){
        qDebug() << i->first << "\n";
        // for(int j = 0; j < i->second.size(); i++){
        //     qDebug() << i->second[i];
        // }
        for(auto &j:i->second){
            qDebug() << j.name;
        }
    }

    int returnValue = a.exec();
    teams.storeData();
    data.storeData();
    playerData.storeData();
    return returnValue;
}
