#ifndef FACTURE_H
#define FACTURE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Facture
{
private:
    int id;
    QString prod_dep;
    float benefice,frais_alim,cout_arr,gain;
public:
    Facture();
    Facture(int,QString,float,float,float,float);
    //crud
    bool ajouterFacture();
    QSqlQueryModel * afficherFacture();
    bool supprimerFacture(int);
    bool modifierFacture();
};

#endif // FACTURE_H
