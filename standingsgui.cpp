#include "standingsgui.h"
#include "ui_standingsgui.h"
#include "mainwindow.h"
#include"user.h"

#include <qmessagebox.h>
StandingsGui::StandingsGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StandingsGui)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    User user;
    ui->textBrowser->setText(user.standings());
    ui->textBrowser->selectAll();
    ui->textBrowser->setAlignment(Qt::AlignCenter);
    multiset<pair<int, string>>::iterator it;
    User u;
    qDebug()<< user.standings().begin();
    if(User::currentUserData.league == "Premier League"){
        if (Admin::GAME_WEEK == 18) {
            cout << "in heree" << endl;
            QString standings = user.standings();
            QStringList lines = standings.split('\n');
            if (!lines.isEmpty()) {
                QStringList parts = lines.first().split(" ");
                QString message = "The Highest Score Is " + parts[0] + " And The Winner Is " + parts[1] + " 🏆";
                QMessageBox *msgBox = new QMessageBox(this);
                msgBox->setText(message);
                msgBox->setWindowTitle("Congratulations!");
                msgBox->show();
            }



        }

    }
    else{
        if(Admin::GAME_WEEK==18){
            QString standings = user.standings();
            QStringList lines = standings.split('\n');
            if (!lines.isEmpty()) {
                QString x = "The Winner is " + QString::fromStdString(lines.first().toStdString());
                QMessageBox *msgBox = new QMessageBox(this);
                msgBox->setText(x);
                msgBox->setWindowTitle("Congratulations!");
                msgBox->show();
            }
        }



    }

}

StandingsGui::~StandingsGui()
{
    delete ui;
}

void StandingsGui::on_commandLinkButton_clicked()
{
    close();
    MainWindow* mainwindowDialog = new MainWindow();
    mainwindowDialog->show();
}

