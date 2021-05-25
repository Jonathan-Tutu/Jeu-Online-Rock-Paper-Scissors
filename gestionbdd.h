#ifndef GESTIONBDD_H
#define GESTIONBDD_H

#include <QString>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QCoreApplication>

class GestionBDD
{
public:
    GestionBDD();
    void ConnexionBDD();

private:

};

#endif // GESTIONBDD_H
