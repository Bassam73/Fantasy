#include "addteamsdatagui.h"
#include "ui_addteamsdatagui.h"
#include "dataentrygui.h"
#include "QString"
#include "qstring.h"
#include "admin.h"
#include "string.h"

Admin a;
AddTeamsDataGui::AddTeamsDataGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddTeamsDataGui)
{
    ui->setupUi(this);
}

AddTeamsDataGui::~AddTeamsDataGui()
{
    delete ui;
}

void AddTeamsDataGui::on_commandLinkButton_clicked()
{
    close();
    DataEntryGui* dataentryguiDialog = new DataEntryGui();
    dataentryguiDialog->show();
}


void AddTeamsDataGui::on_pushButton_clicked()
{
    ui->label_3->clear();
    QString name = ui->teamName->text();
    QString league = ui->teamLeague->currentText();

    if (name.isEmpty()) {

        ui->label_3->setText("Please enter a team name!");
        return;
    }
    bool result =  a.addTeams(name.toStdString(), league.toStdString());
    if (!result && league == "LaLiga")
        ui->label_3->setText("LaLiga already has 10 teams Or team already exists");
    else if (!result && league == "Premier League")
        ui->label_3->setText("Premier League already has 10 teams Or team already exists");
    else if (result && name.length()!=0 && league == "LaLiga") {
        ui->teamName->clear();
        ui->listWidget_2->addItem(name);
    }

    else if (result && name.length()!=0 && league == "Premier League") {
        ui->teamName->clear();
        ui->listWidget->addItem(name);
    }

}



