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

private:
    Ui::TransferGui *ui;
};

#endif // TRANSFERGUI_H
