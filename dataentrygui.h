#ifndef DATAENTRYGUI_H
#define DATAENTRYGUI_H

#include <QDialog>

namespace Ui {
class DataEntryGui;
}

class DataEntryGui : public QDialog
{
    Q_OBJECT

public:
    explicit DataEntryGui(QWidget *parent = nullptr);
    ~DataEntryGui();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::DataEntryGui *ui;
};

#endif // DATAENTRYGUI_H
