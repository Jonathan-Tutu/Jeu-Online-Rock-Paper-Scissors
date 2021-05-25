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

    connect(ui->Valid_Insc,SIGNAL(clicked()),this, SLOT(ValidInscription()));
    connect(ui->Retour_Insc,SIGNAL(clicked()),this, SLOT(BoutonCancelInscrip()));

    ui->EditPswd->setEchoMode(QLineEdit::Password); //Permet de cacher le mot de passe lors de l'écriture
}

void MainWindow::Connexion()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::ValiderConnexion()
{
    //Pour lancer le client
    //Vérification avec la base de données
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
    QRegExp mdp ("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!*?$%]).{8,}$");

    if(!ui->Edit_User_Insc->text().isEmpty())
    {
            if(ui->Edit_mail_Insc->text().contains(mailExp) && !ui->Edit_mail_Insc->text().isEmpty())
            {
                if(!ui->Edit_Mdp_Insc->text().isEmpty() && !ui->Edit_MdpConf_Insc->text().isEmpty() && ui->Edit_Mdp_Insc->text().contains(mdp))
                {
                    if(ui->Edit_Mdp_Insc->text() == ui->Edit_MdpConf_Insc->text())
                    {
                        QByteArray MotDePasseNonCrypte = ui->Edit_Mdp_Insc->text().toStdString().c_str();
                        //Cryptage sha1 mot de passe
                        QString MotDePasseCrypte = QCryptographicHash::hash((MotDePasseNonCrypte),QCryptographicHash::Sha1); //Mdp stocké dans la BDD
                        //TODO
                        //Inscription dans la base de données
                        QMessageBox::information(this, "Compte", "Votre compte à été crée");
                    }
                    else
                    {
                        QMessageBox::critical(this, "Mot de passe", "Les deux mots de passe ne correspondent pas");
                    }
                }
                else
                {
                    QMessageBox::critical(this, "Mot de passe", "Le mot de passe ne correspond pas à un format connu");
                }
            }
            else
            {
                QMessageBox::critical(this, "Adresse mail", "L'adresse mail ne correspond pas à un format connu");
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


