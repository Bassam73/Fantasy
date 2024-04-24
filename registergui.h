#ifndef REGISTERGUI_H
#define REGISTERGUI_H

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

private:
    Ui::RegisterGui *ui;
};

#endif // REGISTERGUI_H
