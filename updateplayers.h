#ifndef UPDATEPLAYERS_H
#define UPDATEPLAYERS_H

#include <QDialog>

namespace Ui {
class UpdatePlayers;
}

class UpdatePlayers : public QDialog
{
    Q_OBJECT

public:
    explicit UpdatePlayers(QWidget *parent = nullptr);
    ~UpdatePlayers();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::UpdatePlayers *ui;
};

#endif // UPDATEPLAYERS_H
