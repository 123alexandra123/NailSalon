
#include "programari.h"
#include "oferte.h"
using namespace std;

Programare::Programare(const string& nume, const string& prenume, int ziua, int luna, int anul, const string& oraInceput, const string& oraFinal,Oferta oferta_curenta)
    : nume(nume), prenume(prenume), ziua(ziua), luna(luna), anul(anul), oraInceput(oraInceput), oraFinal(oraFinal), oferta_curenta(oferta_curenta){}

string Programare::getNume() const{
    return nume;
}

string Programare::getPrenume() const{
    return prenume;
}

int Programare::getZiua() const{
    return ziua;
}

int Programare::getLuna() const{
    return luna;
}

int Programare::getAnul() const{
    return anul;
}

string Programare::getOraInceput() const{
    return oraInceput;
}

string Programare::getOraFinal() const{
    return oraFinal;
}

Oferta Programare::getOferta() const {
    return oferta_curenta;

}

vector<Programare> citesteProgramariDinFisier(){
    vector<Programare> programari;
    ifstream fisier("PROGRAMARI.txt");
    if (!fisier)
    {

        return programari;
    }


    string antet;
    getline(fisier, antet);

    string linie;
    while (getline(fisier, linie))
    {
        stringstream ss(linie);
        string nume, prenume, oraInceput, oraFinal, ziuaStr, lunaStr, anulStr,pret1,durata1,serviciu;
        int ziua, luna, anul;
        int pret,durata;
        getline(ss, nume, ',');
        getline(ss, prenume, ',');
        getline(ss, ziuaStr, ',');
        getline(ss, lunaStr, ',');
        getline(ss, anulStr, ',');
        getline(ss, oraInceput, ',');
        getline(ss, oraFinal, ',');
        getline(ss, serviciu, ',');
        getline(ss,pret1,',');
        getline(ss,durata1);
        ziua = stod(ziuaStr);
        luna = stod(lunaStr);
        anul = stod(anulStr);
        pret = stoi(pret1);
        durata = stoi(durata1);
        programari.push_back(Programare(nume, prenume, ziua, luna, anul, oraInceput, oraFinal,Oferta(serviciu,pret,durata)));

    }

    fisier.close();
    return programari;
}

void vizualizareProgramari(const string& role, const string& nume, const string& prenume){
    vector<Programare> programari = citesteProgramariDinFisier();

    if (programari.empty()){
        cout << "Nu exista programari disponibile.\n";
        return;
    }

    int i=1;
    for (const auto& programare : programari){
        if (role == "manager"){

            cout <<i<<". "<< "Nume: " << programare.getNume() << ", Prenume: " << programare.getPrenume() << ", Data: " << programare.getZiua() << "/" << programare.getLuna() << "/" << programare.getAnul()
            << ", Ora inceput: " << programare.getOraInceput() << ", Ora final: " << programare.getOraFinal() << ", Oferta: ";
            Oferta x = programare.getOferta();
            cout << x << endl;
            i++;
        }

        else if(role=="client" && programare.getNume() == nume && programare.getPrenume() == prenume){
            cout <<i<<". "<< "Nume: " << programare.getNume() << ", Prenume: " << programare.getPrenume() << ", Data: " << programare.getZiua() << "/" << programare.getLuna() << "/" << programare.getAnul()
            << ", Ora inceput: " << programare.getOraInceput() << ", Ora final: " << programare.getOraFinal() << ", Oferta: ";
            Oferta x = programare.getOferta();
            cout << x << endl;
            i++;
        }
    }
    if(i==1) cout<<"Nu aveti nicio programare";
}


void anuleazaProgramare(const string& role, const string& nume, const string& prenume){
    vector<Programare> programari = citesteProgramariDinFisier();

    if(role=="manager"){
        cout << "Programari :\n\n";
        for (size_t i = 0; i < programari.size(); ++i)
        {


            cout << i+1 << ". Nume: " << programari[i].getNume() << ", Prenume: " << programari[i].getPrenume()
                 << ", Data: " << programari[i].getZiua() << "/" << programari[i].getLuna() << "/"
                 << programari[i].getAnul() << ", Ora inceput: " << programari[i].getOraInceput()
                 << ", Ora final: " << programari[i].getOraFinal() << ", Serviciu: "<< programari[i].getOferta().getNumeOferta()
                 << ", Pret: "<< programari[i].getOferta().getPret()<<", Durata: "<< programari[i].getOferta().getDurata()<< endl;

        }
        cout<<"Alege numarul programarii pe care vrei sa o anulezi: ";
        size_t indice;
        cin>>indice;
        if (programari.empty() || indice <= 0 || indice > programari.size()){
            cout << "Nu exista o programare cu acest indice.\n";
            return;
        }

        programari.erase(programari.begin() + (indice-1));
    }
    else if(role=="client"){
        printf("Ati ales optiunea de stergere a unei programari.\n\n");

        printf("Acestea sunt programarile dumneavoastra:\n");
        size_t i;
        int a=1;
        for (i = 0; i < programari.size(); ++i)
        {
            if (role == "client" && programari[i].getNume() == nume && programari[i].getPrenume() == prenume)
            {
               cout << i+1 << ". Nume: " << programari[i].getNume() << ", Prenume: " << programari[i].getPrenume()
                 << ", Data: " << programari[i].getZiua() << "/" << programari[i].getLuna() << "/"
                 << programari[i].getAnul() << ", Ora inceput: " << programari[i].getOraInceput()
                 << ", Ora final: " << programari[i].getOraFinal() << ", Serviciu: "<< programari[i].getOferta().getNumeOferta()
                 << ", Pret: "<< programari[i].getOferta().getPret()<<", Durata: "<< programari[i].getOferta().getDurata()<< endl;
                     a++;
            }
        }

        size_t progr_aleasa;
        cout<<"\nAlege programarea pe care vrei sa o anulezi: ";
        cin>>progr_aleasa;


        if (progr_aleasa < 1 || progr_aleasa > i){
            cout << "Nu exista o programare cu acest indice.\n";
            return;
        }

        size_t in = 0;
        for (size_t i = 0; i < programari.size(); ++i){
            if (programari[i].getNume() == nume && programari[i].getPrenume() == prenume){
                in++;
                if (progr_aleasa == in)
                {
                    programari.erase(programari.begin() + i);
                    break;
                }
            }
        }
    }

    ofstream fisier("PROGRAMARI.txt");
    if (!fisier){
        cout << "Eroare la deschiderea fisierului.\n";
        return;
    }

    fisier << "NUME,PRENUME,ZIUA,LUNA,ANUL,ORA_INCEPUT,ORA_FINAL,OFERTA\n"; // Scrie antetul în fișier

    for (const auto& programare : programari){
        fisier << programare.getNume() << "," << programare.getPrenume() << ","
               << programare.getZiua() << "," << programare.getLuna() << ","
               << programare.getAnul() << "," << programare.getOraInceput() << ","
               << programare.getOraFinal()<<",";
               Oferta x = programare.getOferta();
               fisier << x;
    }
    cout << "Programare anulata cu succes.\n";
}


void scrieProgramariInFisier(const std::vector<Programare>& listaProgramari) {
    std::ofstream outfile("PROGRAMARI.txt");

    if (!outfile.is_open()) {
        std::cerr << "Eroare la deschiderea fisierului de programari.\n";
        return;
    }
    outfile<< "NUME,PRENUME,ZIUA,LUNA,ANUL,ORA_INCEPUT,ORA_FINAL,SERVICIU\n";
    for (const auto& programare : listaProgramari) {
        outfile << programare.getNume() << "," << programare.getPrenume() << "," << programare.getZiua() << "," << programare.getLuna() << "," << programare.getAnul() << ","
                << programare.getOraInceput() << "," << programare.getOraFinal()<<",";
                Oferta x = programare.getOferta();
                outfile << x;
    }

    outfile.close();
}


int comparaOre(const string& ora1, const string& ora2){
    auto timpLaMinute = [](const string& timp) {
        istringstream ss(timp);
        string oraPart, minutePart;
        getline(ss, oraPart, ':');
        getline(ss, minutePart);
        return stoi(oraPart) * 60 + stoi(minutePart);
    };

    int ora1Minute = timpLaMinute(ora1);
    int ora2Minute = timpLaMinute(ora2);

    if (ora1Minute < ora2Minute) {
        return -1;
    } else if (ora1Minute > ora2Minute) {
        return 1;
    } else {
        return 0;
    }
}

bool verificaDataSiOra(int ziua, int luna, int anul, const string& oraInceput, const string& oraFinal) {
    auto timpLaMinute = [](const string& timp) {
        istringstream ss(timp);
        string oraPart, minutPart;
        getline(ss, oraPart, ':');
        getline(ss, minutPart);
        int ora = stoi(oraPart);
        int minut = stoi(minutPart);
        return ora * 60 + minut;
    };

    int oraInceputInt = timpLaMinute(oraInceput);
    int oraFinalInt = timpLaMinute(oraFinal);

    if (ziua < 1 || ziua > 31 || luna < 1 || luna > 12 || anul < 2024 ||
        oraInceputInt < 600 || oraInceputInt > 1199 || oraFinalInt < 600 || oraFinalInt > 1199 ||
        (oraInceputInt >= oraFinalInt))
            return false;
    return true;
}


string toLowercase(const string& text) {
    string lowerText = text;
    transform(lowerText.begin(), lowerText.end(), lowerText.begin(),
                   [](unsigned char c) { return tolower(c); });
    return lowerText;
}


string adaugaMinute(string ora, int minuteAdaugate) {
    int HH = std::stoi(ora.substr(0, 2));
    int MM = std::stoi(ora.substr(3, 2));

    int totalMinute = HH * 60 + MM + minuteAdaugate;

    HH = (totalMinute / 60) % 24;
    MM = totalMinute % 60;

    ostringstream oss;
    oss << setfill('0') << setw(2) << HH << ":" << setw(2) << MM;

    return oss.str();
}


void adaugaProgramare(const string& name, const string& surname) {

    vector<Programare> listaProgramari = citesteProgramariDinFisier();

    string nume, prenume, oraInceput,oraFinal, serviciu;
    int ziua, luna, anul, ok=0;
    nume = name;
    prenume = surname;

    cout << "Introduceti serviciul dorit: ";
    cin.get();
    getline(cin,serviciu);

    vector<Oferta> v = citesteOferteDinFisier();
    for(auto i : v)
        if(toLowercase(serviciu) == toLowercase(i.getNumeOferta())){

            cout << "Introduceti ziua: ";
            cin >> ziua;
            cout << "Introduceti luna: ";
            cin >> luna;
            cout << "Introduceti anul: ";
            cin >> anul;
            cout << "Introduceti ora de inceput (format 24h): ";
            cin >> oraInceput;

            oraFinal=adaugaMinute(oraInceput,i.getDurata());

             if (!verificaDataSiOra(ziua, luna, anul, oraInceput, oraFinal)) {
                cout << "Data sau ora sunt invalide.\n";
                return;
            }

            for (const auto& programare : listaProgramari) {
                if (programare.getZiua() == ziua && programare.getLuna() == luna && programare.getAnul() == anul &&
                    ((comparaOre(oraInceput, programare.getOraInceput()) >= 0 && comparaOre(oraInceput, programare.getOraFinal()) < 0) ||
                    (comparaOre(oraFinal, programare.getOraInceput()) > 0 && comparaOre(oraFinal, programare.getOraFinal()) <= 0) ||
                    (comparaOre(oraInceput, programare.getOraInceput()) <= 0 && comparaOre(oraFinal, programare.getOraFinal()) >= 0))) {
                    cout << "Exista deja o programare in intervalul specificat.\n";
                    return;
                }
            }

             Programare nouaProgramare(nume, prenume, ziua, luna, anul, oraInceput, oraFinal, i);
             listaProgramari.push_back(nouaProgramare);
             ok=1;
             break;
        }

    if(ok==0) cout<<"Nu avem serviciul dorit.";
    else{
        cout << "Programare adaugata cu succes.\n";
        scrieProgramariInFisier(listaProgramari);
    }

}
