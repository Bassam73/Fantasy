#ifndef MYPROFILEGUI_H
#define MYPROFILEGUI_H

#include <QDialog>

namespace Ui {
class MyProfileGui;
}

class MyProfileGui : public QDialog
{
    Q_OBJECT

public:
    explicit MyProfileGui(QWidget *parent = nullptr);
    ~MyProfileGui();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::MyProfileGui *ui;
};

#endif // MYPROFILEGUI_H
