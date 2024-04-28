#ifndef MYPROFILEGUI_H
#define MYPROFILEGUI_H

#include <QDialog>
#include <User.h>
#include "admin.h"


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
    void on_editButton_clicked(bool ok);

private:
   Ui::MyProfileGui *ui;
    Admin addData;
};

#endif // MYPROFILEGUI_H
