#ifndef DATAENTRYGUI_H
#define DATAENTRYGUI_H

#include <QDialog>
#include "addteamsdatagui.h"
#include "editteamsdatagui.h"
#include "deleteteamsdatagui.h"

namespace Ui {
class DataEntryGui;
}

class DataEntryGui : public QDialog
{
    Q_OBJECT

public:
    explicit DataEntryGui(QWidget *parent = nullptr);
    ~DataEntryGui();

private slots:
    void on_commandLinkButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::DataEntryGui *ui;
    AddTeamsDataGui *addteamsdatagui;
    EditTeamsDataGui *editteamsdatagui;
    DeleteTeamsDataGui *deleteteamsdatagui;

};

#endif // DATAENTRYGUI_H
