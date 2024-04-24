#include "stats.h"
#include "ui_stats.h"
#include "mainwindow.h"
Stats::Stats(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Stats)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

}

Stats::~Stats()
{
    delete ui;
}

void Stats::on_commandLinkButton_clicked()
{
    close();
    MainWindow* mainwindowDialog = new MainWindow();
    mainwindowDialog->show();
}

