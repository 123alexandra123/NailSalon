
#ifndef PROGRAMARI_H
#define PROGRAMARI_H

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include<iomanip>
#include "oferte.h"

using namespace std;

class Programare {
private:
    string nume;
    string prenume;
    int ziua;
    int luna;
    int anul;
    string oraInceput;
    string oraFinal;
    Oferta oferta_curenta;

public:
    Programare(const string& nume, const string& prenume, int ziua, int luna, int anul, const string& oraInceput,
               const string& oraFinal,Oferta oferta_curenta);
    string getNume() const;
    string getPrenume() const;
    int getZiua() const;
    int getLuna() const;
    int getAnul() const;
    string getOraInceput() const;
    string getOraFinal() const;
    Oferta getOferta() const;
};

vector<Programare> citesteProgramariDinFisier(const string& numeFisier);
void vizualizareProgramari(const string& role, const string& nume, const string& prenume);
void anuleazaProgramare(const string& role, const string& nume, const string& prenume);
void adaugaProgramare(const string& name, const string& surname);
void scrieProgramariInFisier(const std::string& numeFisier);

#endif // PROGRAMARI_H
