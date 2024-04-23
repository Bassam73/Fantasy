#ifndef MYTEAM_H
#define MYTEAM_H

#include <QDialog>
namespace Ui {
class MyTeam;
}

class MyTeam : public QDialog
{
    Q_OBJECT

public:
    explicit MyTeam(QWidget *parent = nullptr);
    ~MyTeam();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::MyTeam *ui;

};

#endif // MYTEAM_H
