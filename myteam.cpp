#include "myteam.h"
#include "ui_myteam.h"
#include "mainwindow.h"

#include <TransferGui.h>
MyTeam::MyTeam(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyTeam)
{
    ui->setupUi(this);
    setPlayers();
    this->setFixedSize(this->width(), this->height());
}

MyTeam::~MyTeam()
{
    delete ui;
}

void MyTeam::on_commandLinkButton_clicked()
{
    close();

    MainWindow* mainwindowDialog = new MainWindow();
    mainwindowDialog->show();
}

void MyTeam::setPlayers(){
    double point=0;
    for(auto i = User::usersTeam.begin(); i != User::usersTeam.end(); i++){
        QString playerName = QString::fromStdString(i->first);

        point +=i->second.points;

        if(i->second.position == "ATT"){
            if(ui->updateLabel_9->text() == ""){
                ui->updateLabel_9->setText(playerName);
            }
            else if(ui->updateLabel_10->text() == ""){
                ui->updateLabel_10->setText(playerName);
            }
            else{
                ui->updateLabel_11->setText(playerName);
            }

        }
        else if(i->second.position == "MID"){
            if(ui->updateLabel_6->text() == ""){
                ui->updateLabel_6->setText(playerName);
            }
            else if(ui->updateLabel_7->text() == ""){
                ui->updateLabel_7->setText(playerName);
            }
            else{
                ui->updateLabel_8->setText(playerName);
            }
        }
        else if(i->second.position == "DEF"){
            if(ui->updateLabel_2->text() == ""){
                ui->updateLabel_2->setText(playerName);
            }
            else if(ui->updateLabel_3->text() == ""){
                ui->updateLabel_3->setText(playerName);
            }
            else if(ui->updateLabel_4->text() == ""){
                ui->updateLabel_4->setText(playerName);
            }
            else{
                ui->updateLabel_5->setText(playerName);
            }

        }
        else if(i->second.position == "GK"){
            ui->updateLabel->setText(playerName);

        }

    }
    ui->label_4->setText( QString::number(point));
}
