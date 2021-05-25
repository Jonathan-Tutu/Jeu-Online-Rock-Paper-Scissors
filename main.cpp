#include "mainwindow.h"
#include "gestionbdd.h"

#include <QApplication>
#include <QSharedMemory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GestionBDD test;

    test.ConnexionBDD();

    QSharedMemory sharedMemory("{69B55631-A712-4d8c-8852-A8ED297EF439}"); //On donne un GUID à l'espace mémoire histoire qu'il soit unique

       if(!sharedMemory.create(sizeof(int))) //Si on ne peut pas créer l'espace mémoire c'est qu'il existe déjà
       {
           QMessageBox msgBox;
           msgBox.setIcon(QMessageBox::Information);
           msgBox.setWindowTitle("IHM_CLIENT");
           msgBox.setText("L'application est déjà lancée");
           msgBox.exec();
           return 1;
       }

    MainWindow w;
    w.setFixedSize(251,341);
    w.show();
    return a.exec();
}
