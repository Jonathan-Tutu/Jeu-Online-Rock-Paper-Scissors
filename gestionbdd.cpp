#include "gestionbdd.h"

GestionBDD::GestionBDD()
{

}

void GestionBDD::ConnexionBDD()
{
    // Préparation de la connexion via ODBC sur la base de données HFSQL ESA_Lorawan
    QSqlDatabase dbase = QSqlDatabase::addDatabase("QODBC");
    QString QStrCnxDatabase = QString("DRIVER={MariaDB ODBC 3.0 Driver};Server Name=")+QString("localhost")+QString(";Database=villageois;UID=root;PWD=123456789;");
    dbase.setDatabaseName(QStrCnxDatabase);

    if(dbase.open())
    {
        qDebug() << "Connecte";
    }
    else
    {
        qDebug() << dbase.lastError();
    }

}
