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


    Admin mainAdmin ;
    User mainUser(mainAdmin.usersList);
    string name ="uSER";

    MainWindow w;
    w.show();
    return a.exec();
}
