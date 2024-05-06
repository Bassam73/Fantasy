#ifndef TRANSFERGUI_H
#define TRANSFERGUI_H

#include <QDialog>

namespace Ui {
class TransferGui;
}

class TransferGui : public QDialog
{
    Q_OBJECT

public:
    explicit TransferGui(QWidget *parent = nullptr);
    ~TransferGui();

private slots:
    void openPlayerWindow();
    void updateLabel(const QString &playerName);


    void on_pushButton_clicked();

private:
    Ui::TransferGui *ui;
    QString currentPos;
};

#endif // TRANSFERGUI_H
