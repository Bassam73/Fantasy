#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "admin.h"
#include "user.h"
#include "registergui.h"
#include "usersdata.h"
vector<User> Admin::usersList;

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

    for(int i = 0; i < Admin::usersList.size(); i++){
        qDebug() << Admin::usersList[i].id <<" "<< Admin::usersList[i].name;
    }

    // User uu("Bassam", "1234" , "ayhaga");
    // User gg("Bassssssam", "ssad2w" , "ayhaga");
    // Admin::usersList.push_back(gg);
    // Admin::usersList.push_back(uu);
    RegisterGui w;
    w.show();


    return a.exec();
}
