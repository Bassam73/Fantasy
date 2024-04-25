#ifndef LOGINGUI_H
#define LOGINGUI_H

#include <QDialog>

namespace Ui {
class LoginGui;
}

class LoginGui : public QDialog
{
    Q_OBJECT

public:
    explicit LoginGui(QWidget *parent = nullptr);
    ~LoginGui();

private:
    Ui::LoginGui *ui;
};

#endif // LOGINGUI_H
