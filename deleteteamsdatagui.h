#ifndef DELETETEAMSDATAGUI_H
#define DELETETEAMSDATAGUI_H

#include <QDialog>

namespace Ui {
class DeleteTeamsDataGui;
}

class DeleteTeamsDataGui : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteTeamsDataGui(QWidget *parent = nullptr);
    ~DeleteTeamsDataGui();

private slots:
    void on_commandLinkButton_clicked();

    void on_teamLeague_activated(int index);

    void on_pushButton_clicked();

private:
    Ui::DeleteTeamsDataGui *ui;
};

#endif // DELETETEAMSDATAGUI_H
