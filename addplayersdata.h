#ifndef ADDPLAYERSDATA_H
#define ADDPLAYERSDATA_H

#include <QDialog>

namespace Ui {
class AddPlayersData;
}

class AddPlayersData : public QDialog
{
    Q_OBJECT

public:
    explicit AddPlayersData(QWidget *parent = nullptr);
    ~AddPlayersData();

private slots:
    void on_commandLinkButton_clicked();

    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

private:
    Ui::AddPlayersData *ui;
};

#endif // ADDPLAYERSDATA_H
