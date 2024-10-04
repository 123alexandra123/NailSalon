
#ifndef OFERTE_H
#define OFERTE_H


#include <string>
#include<vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class Oferta {
private:
    string numeOferta;
    int pret;
    int durata;


public:
    Oferta(const string& nume, int pret,int durata);
    string getNumeOferta() const;
    int getPret() const;
    int getDurata() const;
    friend ostream & operator <<(ostream &,Oferta &);

};


vector<Oferta> citesteOferteDinFisier();
void vizualizareOferte();
void adaugaOferta();
void stergeOferta();


#endif // OFERTE_H
