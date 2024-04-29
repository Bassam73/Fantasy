#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "admin.h"
#include "user.h"
#include "registergui.h"
#include "usersdata.h"
#include "teamdata.h"

vector<User> Admin::usersList;
User User::currentUserData;


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


    RegisterGui w;
    w.show();


    int returnValue = a.exec();
    teams.storeData();
    data.storeData();
    return returnValue;
}
