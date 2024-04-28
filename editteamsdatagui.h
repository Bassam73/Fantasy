#ifndef EDITTEAMSDATAGUI_H
#define EDITTEAMSDATAGUI_H

#include <QDialog>

namespace Ui {
class EditTeamsDataGui;
}

class EditTeamsDataGui : public QDialog
{
    Q_OBJECT

public:
    explicit EditTeamsDataGui(QWidget *parent = nullptr);
    ~EditTeamsDataGui();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::EditTeamsDataGui *ui;
};

#endif // EDITTEAMSDATAGUI_H
