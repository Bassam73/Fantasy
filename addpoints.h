#ifndef ADDPOINTS_H
#define ADDPOINTS_H

#include <QDialog>

namespace Ui {
class addpoints;
}

class addpoints : public QDialog
{
    Q_OBJECT

public:
    explicit addpoints(QWidget *parent = nullptr);
    ~addpoints();

private slots:
    void on_commandLinkButton_clicked();

    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_comboBox_4_activated(int index);

    void on_comboBox_5_activated(int index);

private:
    Ui::addpoints *ui;
};

#endif // ADDPOINTS_H
