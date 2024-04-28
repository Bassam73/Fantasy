#include "myprofilegui.h"
#include "ui_myprofilegui.h"
#include "mainwindow.h"
#include "admin.h"
#include "usersdata.h"
#include <QInputDialog>

MyProfileGui::MyProfileGui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyProfileGui)
{
    ui->setupUi(this);
    ui->label_3->setText(User::currentUserData.name.data());
    ui->label_4->setText(User::currentUserData.league.data());
    ui->label_5->setText("99999");

    // Connect the clicked signal to the on_editButton_clicked slot with UniqueConnection
    QObject::connect(ui->editButton, &QPushButton::clicked, this, &MyProfileGui::on_editButton_clicked);
}

MyProfileGui::~MyProfileGui()
{
    delete ui;
}

void MyProfileGui::on_commandLinkButton_clicked()
{
    close(); // Close the current dialog

    // Create a new MainWindow instance
    MainWindow *mainwindowDialog = new MainWindow();
    mainwindowDialog->show(); // Show the MainWindow
}

// Add a member variable to track whether the slot is currently executing
void MyProfileGui::on_editButton_clicked(bool ok)
{
    // Disconnect the signal-slot connection temporarily
    QObject::disconnect(ui->editButton, &QPushButton::clicked, this, &MyProfileGui::on_editButton_clicked);

    qDebug() << "Edit button clicked";

    QString newUsername = QInputDialog::getText(this, tr("Edit Username"), tr("New Username:"), QLineEdit::Normal, QString(), &ok);
    if (ok && !newUsername.isEmpty()) {
        // Update the username in the JSON file and the text label
        for (User &user : addData.usersList) {
            if (user.id == User::currentUserData.id) {
                user.name = newUsername.toStdString();
                break;
            }
        }
        // Update the JSON file with the modified data
        UsersData usersData;
        usersData.storeData();

        // Update the username in the text label
        ui->label_3->setText(newUsername);

        // Update the current user data
        User::currentUserData.name = newUsername.toStdString();
    }

    // Reconnect the signal-slot connection after the slot has finished executing
    QObject::connect(ui->editButton, &QPushButton::clicked, this, &MyProfileGui::on_editButton_clicked);
}
