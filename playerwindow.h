#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H
#include <vector>
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
    static int playersCounter;
    static QVector<QString> playersInSquad;

signals:
    void playerSelected(const QString &playerName, double &userBank);

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
