#ifndef CONTROLUSERSGUI_H
#define CONTROLUSERSGUI_H

#include <QDialog>

namespace Ui {
class ControlUsersGui;
}

class ControlUsersGui : public QDialog
{
    Q_OBJECT

public:
    explicit ControlUsersGui(QWidget *parent = nullptr);
    ~ControlUsersGui();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::ControlUsersGui *ui;
};

#endif // CONTROLUSERSGUI_H
