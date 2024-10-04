
#include "oferte.h"
using namespace std;

Oferta::Oferta(const string& nume, int pret,int durata) : numeOferta(nume), pret(pret), durata(durata) {}

string Oferta::getNumeOferta() const {
    return numeOferta;
}

int Oferta::getPret() const {
    return pret;
}
int Oferta::getDurata() const{
    return durata;
}

ostream & operator <<(ostream &st,Oferta &a){

    st << a.numeOferta << ","<< a.pret << "," << a.durata << endl;
    return st;
}

vector<Oferta> citesteOferteDinFisier() {
    vector<Oferta> oferte;
    ifstream fisier("OFERTE.txt");
    if (!fisier) {
        return oferte;
    }

    string antet;
    getline(fisier, antet);

    string linie;
    while (getline(fisier, linie)) {
        stringstream ss(linie);
        string nume;
        string pretStr;
        string durata_s;
        double pret;
        int durata;
        getline(ss, nume, ',');
        getline(ss, pretStr, ',');
        getline(ss,durata_s);
        pret = stod(pretStr);
        durata = stoi(durata_s);
        oferte.push_back(Oferta(nume, pret,durata));

    }

    fisier.close();
    return oferte;
}

void vizualizareOferte() {

    vector<Oferta> oferte = citesteOferteDinFisier();

    if (oferte.empty()) {
        cout << "Nu exista oferte disponibile.\n";
        return;
    }

    cout << "Oferte disponibile:\n\n";
    cout << "SERVICIU,PRET,DURATA\n\n";
    int i=1;
    for (auto oferta : oferte){
        cout << i << ". ";
        cout << oferta;
        i++;
    }
}

void adaugaOferta() {
    vector<Oferta> oferte = citesteOferteDinFisier();
    string nume;
    double pret;
    int durata;
    cout<<"Adaugati o oferta: "<<endl;
    cout<<"Nume: ";
    cin.get();
    getline(cin,nume);
    cout<<"Pret: ";
    cin >> pret;
    cout <<"Durata: ";
    cin >> durata;
    oferte.push_back(Oferta(nume, pret,durata));

    ofstream fisier("OFERTE.txt");
    if (!fisier) {
        cout << "Eroare la deschiderea fișierului.\n";
        return;
    }

    fisier << "OFERTA,PRET,DURATA\n";
    for (const auto& oferta : oferte) {
        fisier << oferta.getNumeOferta() << "," << oferta.getPret() << "," << oferta.getDurata() << endl;
    }

    cout << "Oferta adaugata cu succes.\n";
}

void stergeOferta() {
    vector<Oferta> oferte = citesteOferteDinFisier();

    if (oferte.empty()) {
        cout << "Nu există oferte disponibile pentru ștergere.\n";
        return;
    }


    cout << "Oferte disponibile pentru stergere:\n";
    for (size_t i = 0; i < oferte.size(); ++i) {
        cout << i+1 << ". Nume: " << oferte[i].getNumeOferta() << ", Pret: " << oferte[i].getPret() << ", Durata: " << oferte[i].getDurata() << endl;
    }

    cout<<"Ce oferta vreti sa stergeti?"<<endl;
    size_t indice;
    cin>>indice;

    if (indice <= 0 || indice > oferte.size()) {
        cout << "Indicele introdus nu corespunde unei oferte.\n";
        return;
    }

    oferte.erase(oferte.begin() + (indice-1));

    ofstream fisier("OFERTE.txt");
    if (!fisier) {
        cout << "Eroare la deschiderea fișierului.\n";
        return;
    }

    fisier << "OFERTA,PRET,DURATA\n";
    for (const auto& oferta : oferte) {
        fisier << oferta.getNumeOferta() << "," << oferta.getPret() << "," << oferta.getDurata() << endl;
    }

    cout << "Oferta stearsa cu succes.\n";
}




