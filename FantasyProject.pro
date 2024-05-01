QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addplayersdata.cpp \
    addpoints.cpp \
    addteamsdatagui.cpp \
    admin.cpp \
    adminhomegui.cpp \
    dataentrygui.cpp \
    deleteplayersgui.cpp \
    deleteteamsdatagui.cpp \
    editteamsdatagui.cpp \
    loginui.cpp \
    main.cpp \
    mainwindow.cpp \
    match.cpp \
    myprofilegui.cpp \
    myteam.cpp \
    player.cpp \
    playerdata.cpp \
    registergui.cpp \
    standingsgui.cpp \
    stats.cpp \
    team.cpp \
    teamdata.cpp \
    updateplayers.cpp \
    updateplayersgui.cpp \
    updateteamsgui.cpp \
    user.cpp \
    usersdata.cpp \
    utils.cpp

HEADERS += \
    addplayersdata.h \
    addpoints.h \
    addteamsdatagui.h \
    admin.h \
    adminhomegui.h \
    dataentrygui.h \
    deleteplayersgui.h \
    deleteteamsdatagui.h \
    editteamsdatagui.h \
    loginui.h \
    mainwindow.h \
    match.h \
    myprofilegui.h \
    myteam.h \
    player.h \
    playerdata.h \
    registergui.h \
    standingsgui.h \
    stats.h \
    team.h \
    teamdata.h \
    updateplayers.h \
    updateplayersgui.h \
    updateteamsgui.h \
    user.h \
    usersdata.h \
    utils.h

FORMS += \
    addplayersdata.ui \
    addpoints.ui \
    addteamsdatagui.ui \
    adminhomegui.ui \
    dataentrygui.ui \
    deleteplayersgui.ui \
    deleteteamsdatagui.ui \
    editteamsdatagui.ui \
    loginui.ui \
    mainwindow.ui \
    myprofilegui.ui \
    myteam.ui \
    registergui.ui \
    standingsgui.ui \
    stats.ui \
    updateplayers.ui \
    updateplayersgui.ui \
    updateteamsgui.ui

TRANSLATIONS += \
    FantasyProject_en_GB.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc
