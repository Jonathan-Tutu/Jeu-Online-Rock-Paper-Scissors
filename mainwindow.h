#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QDialog>
#include <QDebug>
#include <QtNetwork/QTcpSocket>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QUiLoader>
#include <QFile>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void Connexion();
    void Inscription();
    void ValidInscription();
    void ValiderConnexion();
    void BoutonCancel();
    void BoutonCancelInscrip();

private:
    Ui::MainWindow *ui;
    QPushButton *Valider;
    QPushButton *Cancel;
    QLineEdit *Login;
    QLineEdit *Mail;
    QLineEdit *Mdp;
    QLineEdit *MdpConfir;
    QDialog *FenetLogin;
    QDialog *FenetInscrip;
    QTcpSocket *masocket;
};
#endif // MAINWINDOW_H
