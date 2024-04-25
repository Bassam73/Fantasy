#ifndef LOGING_H
#define LOGING_H
#include <iostream>
using namespace std;

#include <QMainWindow>

namespace Ui {
class loginG;
}

class loginG : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginG(QWidget *parent = nullptr);
    ~loginG();
    bool checkRegisteredUser(string name, string);

private slots:
    void on_pushButton_clicked();

private:
    Ui::loginG *ui;
};

#endif // LOGING_H
