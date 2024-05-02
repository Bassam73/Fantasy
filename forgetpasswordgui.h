#ifndef FORGETPASSWORDGUI_H
#define FORGETPASSWORDGUI_H

#include <QDialog>

namespace Ui {
class forgetPasswordgui;
}

class forgetPasswordgui : public QDialog
{
    Q_OBJECT

public:
    explicit forgetPasswordgui(QWidget *parent = nullptr);
    ~forgetPasswordgui();

private slots:
    void on_pushButton_clicked();

private:
    Ui::forgetPasswordgui *ui;
};

#endif // FORGETPASSWORDGUI_H
