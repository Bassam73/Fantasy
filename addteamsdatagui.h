#ifndef ADDTEAMSDATAGUI_H
#define ADDTEAMSDATAGUI_H

#include <QDialog>

namespace Ui {
class AddTeamsDataGui;
}

class AddTeamsDataGui : public QDialog
{
    Q_OBJECT

public:
    explicit AddTeamsDataGui(QWidget *parent = nullptr);
    ~AddTeamsDataGui();

private slots:
    void on_commandLinkButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::AddTeamsDataGui *ui;
};

#endif // ADDTEAMSDATAGUI_H
