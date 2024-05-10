#include "stats.h"
#include "ui_stats.h"
#include "mainwindow.h"
#include"User.h"
Stats::Stats(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Stats)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

    User user;
    ui->textBrowser->setText(user.stats("Goals"));
    ui->textBrowser->selectAll();
    ui->textBrowser->setAlignment(Qt::AlignCenter);

    QString x = user.stats("Clean Sheets");
    qDebug()<<x;

    ui->textBrowser_2->setText(user.stats("Yellow Cards"));
    ui->textBrowser_2->selectAll();
    ui->textBrowser_2->setAlignment(Qt::AlignCenter);

    ui->textBrowser_3->setText(user.stats("Assists"));
    ui->textBrowser_3->selectAll();
    ui->textBrowser_3->setAlignment(Qt::AlignCenter);


    ui->textBrowser_4->clear(); // Clear the text browser
    ui->textBrowser_4->setText(user.stats("Clean Sheets"));
    ui->textBrowser_4->selectAll();
    ui->textBrowser_4->setAlignment(Qt::AlignCenter);


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

