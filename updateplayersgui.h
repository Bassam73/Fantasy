#ifndef UPDATEPLAYERSGUI_H
#define UPDATEPLAYERSGUI_H

#include <QDialog>

namespace Ui {
class UpdatePLayersGui;
}

class UpdatePLayersGui : public QDialog
{
    Q_OBJECT

public:
    explicit UpdatePLayersGui(QWidget *parent = nullptr);
    ~UpdatePLayersGui();

private slots:
    void on_commandLinkButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::UpdatePLayersGui *ui;
};

#endif // UPDATEPLAYERSGUI_H
