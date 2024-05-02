#ifndef LOGINUI_H
#define LOGINUI_H
#include <iostream>
using namespace std;

#include <QDialog>

namespace Ui {
class LoginUI;
}

class LoginUI : public QDialog
{
    Q_OBJECT

public:
    explicit LoginUI(QWidget *parent = nullptr);
    ~LoginUI();


private slots:
    void on_pushButton_clicked();


    void on_commandLinkButton_clicked();

private:
    Ui::LoginUI *ui;
};

#endif // LOGINUI_H
