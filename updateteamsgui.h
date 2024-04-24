#ifndef UPDATETEAMSGUI_H
#define UPDATETEAMSGUI_H

#include <QDialog>

namespace Ui {
class UpdateTeamsGui;
}

class UpdateTeamsGui : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateTeamsGui(QWidget *parent = nullptr);
    ~UpdateTeamsGui();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::UpdateTeamsGui *ui;
};

#endif // UPDATETEAMSGUI_H
