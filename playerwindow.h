#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class PlayerWindow;
}

class PlayerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerWindow(QWidget *parent = nullptr);
    ~PlayerWindow();
    static std::string currentPosition;

signals:
    void playerSelected(const QString &playerName);

public slots:
    void loadPlayersFromJson();
    void filterPlayersByTeam(const QString &teamName);
    void filterPlayersByCostFilter(const QString &costFilter);
    //  void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_okButton_clicked();


private:
    Ui::PlayerWindow *ui;
};

#endif // PLAYERWINDOW_H
