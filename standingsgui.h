#ifndef STANDINGSGUI_H
#define STANDINGSGUI_H

#include <QDialog>

namespace Ui {
class StandingsGui;
}

class StandingsGui : public QDialog
{
    Q_OBJECT

public:
    explicit StandingsGui(QWidget *parent = nullptr);
    ~StandingsGui();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::StandingsGui *ui;
};

#endif // STANDINGSGUI_H
