#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "mainwindow.h"
#include "admin.h"
#include "registergui.h"

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
    Admin mainAdmin ;
    User mainUser(mainAdmin.usersList);
    string name ="uSER";

    RegisterGui r ;
    r.show();
    return a.exec();
}
