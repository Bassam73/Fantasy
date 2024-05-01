#ifndef ADDPOINTSGUI_H
#define ADDPOINTSGUI_H

#include <QDialog>

namespace Ui {
class AddPointsGui;
}

class AddPointsGui : public QDialog
{
    Q_OBJECT

public:
    explicit AddPointsGui(QWidget *parent = nullptr);
    ~AddPointsGui();

private:
    Ui::AddPointsGui *ui;
};

#endif // ADDPOINTSGUI_H
