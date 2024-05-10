#ifndef LUCKYWHEELGUI_H
#define LUCKYWHEELGUI_H

#include <QDialog>

namespace Ui {
class LuckyWheelGui;
}

class LuckyWheelGui : public QDialog
{
    Q_OBJECT

public:
    explicit LuckyWheelGui(QWidget *parent = nullptr);
    ~LuckyWheelGui();

private:
    Ui::LuckyWheelGui *ui;
};

#endif // LUCKYWHEELGUI_H
