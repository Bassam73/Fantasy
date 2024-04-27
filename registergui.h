#ifndef REGISTERGUI_H
#define REGISTERGUI_H
#include <iostream>
using namespace std;
#include <QDialog>

namespace Ui {
class RegisterGui;
}

class RegisterGui : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterGui(QWidget *parent = nullptr);
    ~RegisterGui();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    // void on_registerButton_clicked();

private:
    Ui::RegisterGui *ui;
};

#endif // REGISTERGUI_H
