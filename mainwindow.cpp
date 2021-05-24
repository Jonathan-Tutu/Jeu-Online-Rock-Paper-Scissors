#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QCryptographicHash>
#include <QThread>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    masocket = new QTcpSocket;

    connect(ui->BoutonInscription, SIGNAL(clicked()),this, SLOT(Inscription()));
    connect(ui->BoutonQuitter,SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(ui->BoutonConnexion,SIGNAL(clicked()),this,SLOT(Connexion()));

    connect(ui->ConnexionLogin,SIGNAL(clicked()),this, SLOT(ValiderConnexion()));
    connect(ui->CancelLogin,SIGNAL(clicked()),this, SLOT(BoutonCancelConnexion()));

}

void MainWindow::Connexion()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::ValiderConnexion()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile("C:\\Users\\Jonathan\\Desktop\\build-IHM_CLIENT_V2-Desktop_Qt_5_15_0_MinGW_64_bit-Release\\release\\IHM_CLIENT_V2.exe"));
}

void MainWindow::BoutonCancelConnexion()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::Inscription()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::BoutonCancelInscrip()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::ValidInscription()
{
    QRegExp mailExp ("^[\\w|\\.]+@[\\w]+\\.[\\w]{2,4}$");
    if(!Login->text().isEmpty())
    {
        if(Mail->text().contains(mailExp) && !Mail->text().isEmpty())
        {
            if(Mdp->text() == MdpConfir->text() && !Mdp->text().isEmpty() && !MdpConfir->text().isEmpty())
            {
                    QByteArray MotDePasseNonCrypte = Mdp->text().toStdString().c_str();
                    //Cryptage sha1 mot de passe
                    QString MotDePasseCrypte = QCryptographicHash::hash((MotDePasseNonCrypte),QCryptographicHash::Sha1); //Mdp stocké dans la BDD



                    QMessageBox::information(this, "Compte", "Votre compte à été crée");
            }
            else
            {
                QMessageBox::critical(this, "Mot de passe", "Les deux mots de passe ne correspondent pas");
            }
        }
        else
        {
            QMessageBox::critical(this, "Adresse mail", "L'adresse mail ne correspond pas à un format donnés");
        }
    }
    else
    {
        QMessageBox::critical(this, "Identifiant", "Votre identifiant n'est pas valide");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


