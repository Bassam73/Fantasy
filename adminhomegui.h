#ifndef ADMINHOMEGUI_H
#define ADMINHOMEGUI_H

#include <QDialog>

namespace Ui {
class AdminHomeGui;
}

class AdminHomeGui : public QDialog
{
    Q_OBJECT

public:
    explicit AdminHomeGui(QWidget *parent = nullptr);
    ~AdminHomeGui();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::AdminHomeGui *ui;
};

#endif // ADMINHOMEGUI_H
