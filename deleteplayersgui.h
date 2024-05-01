#ifndef DELETEPLAYERSGUI_H
#define DELETEPLAYERSGUI_H

#include <QDialog>

namespace Ui {
class DeletePlayersGui;
}

class DeletePlayersGui : public QDialog
{
    Q_OBJECT

public:
    explicit DeletePlayersGui(QWidget *parent = nullptr);
    ~DeletePlayersGui();

private slots:
    void on_commandLinkButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::DeletePlayersGui *ui;
};

#endif // DELETEPLAYERSGUI_H
