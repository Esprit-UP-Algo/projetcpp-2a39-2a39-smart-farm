#ifndef CULTURE_H
#define CULTURE_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>

class culture
{
private:
    int id;
    float qualite,pluv,hum,ten,temp;
public:
    culture();
    culture(int,float,float,float,float,float);
    bool ajouterCulture();
    QSqlQueryModel * afficherCulture();
    bool supprimerCulture(int);
    bool modifierCulture();
};

#endif // CULTURE_H
