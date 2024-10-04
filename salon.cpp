#include "salon.h"
#include "oferte.h"
#include "programari.h"
#include <iostream>
#include <cstdlib>

// Definiții pentru culori
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

using namespace std;

void Salon::displayClientMenu()
{
    cout << ANSI_COLOR_CYAN "==================================\n";
    cout << "|     SALON DE UNGHII APP        |\n";
    cout << ANSI_COLOR_CYAN "==================================\n";
    cout << "|        " ANSI_COLOR_YELLOW "MENIU CLIENT" ANSI_COLOR_CYAN "            |\n";
    cout << "==================================\n";
    cout << "| 1. " ANSI_COLOR_MAGENTA "Programare" ANSI_COLOR_CYAN "                  |\n";
    cout << "| 2. " ANSI_COLOR_MAGENTA "Vizualizare oferte" ANSI_COLOR_CYAN "          |\n";
    cout << "| 3. " ANSI_COLOR_MAGENTA "Vizualizare programari" ANSI_COLOR_CYAN "      |\n";
    cout << "|    " ANSI_COLOR_MAGENTA "personale" ANSI_COLOR_CYAN "                   |\n";
    cout << "| 4. " ANSI_COLOR_MAGENTA "Anulare programare" ANSI_COLOR_CYAN "          |\n";
    cout << "| 5. " ANSI_COLOR_MAGENTA "Iesire" ANSI_COLOR_CYAN "                      |\n";
    cout << "==================================\n" ANSI_COLOR_RESET;
    cout << "Alege o optiune: ";
}

void Salon::displayManagerMenu()
{
    cout << ANSI_COLOR_CYAN "==================================\n";
    cout << "|     SALON DE UNGHII APP        |\n";
    cout << ANSI_COLOR_CYAN "==================================\n";
    cout << "|       " ANSI_COLOR_YELLOW "MENIU MANAGER" ANSI_COLOR_CYAN "            |\n";
    cout << "==================================\n";
    cout << "| 1. " ANSI_COLOR_YELLOW "Vizualizare programari" ANSI_COLOR_CYAN "      |\n";
    cout << "| 2. " ANSI_COLOR_YELLOW "Anulare programare" ANSI_COLOR_CYAN "          |\n";
    cout << "| 3. " ANSI_COLOR_YELLOW "Vizualizare oferte" ANSI_COLOR_CYAN "          |\n";
    cout << "| 4. " ANSI_COLOR_YELLOW "Adaugare oferta" ANSI_COLOR_CYAN "             |\n";
    cout << "| 5. " ANSI_COLOR_YELLOW "Stergere oferta" ANSI_COLOR_CYAN "             |\n";
    cout << "| 6. " ANSI_COLOR_YELLOW "Iesire" ANSI_COLOR_CYAN "                      |\n";
    cout << "==================================\n" ANSI_COLOR_RESET;
    cout << "Alege o optiune: ";
}

void Salon::run()
{
    if (role == "client")
    {
        int choice;

        do
        {

            displayClientMenu();
            cin >> choice;

            switch (choice)
            {
            case 1:
                system("cls");
                adaugaProgramare(name,surname);
                askToReturnToMainMenu();
                break;
            case 2:
                system("cls");
                vizualizareOferte();
                askToReturnToMainMenu();
                break;
            case 3:
                system("cls");
                vizualizareProgramari(role, name, surname);
                askToReturnToMainMenu();
                break;
            case 4:
                system("cls");
                anuleazaProgramare(role, name, surname);
                askToReturnToMainMenu();
                break;
            case 5:
                cout << "Iesire din aplicatie.\n";
                break;
            default:
                cout << "Optiune invalida. Te rog sa alegi o optiune valida.\n";
                break;
            }
        }
        while (choice != 5);
    }
    else if (role == "manager")
    {
        int choice;

        do
        {

            displayManagerMenu();
            cin >> choice;

            switch (choice)
            {
            case 1:
                system("cls");
                vizualizareProgramari(role, name, surname);
                askToReturnToMainMenu();
                break;
            case 2:
                system("cls");
                anuleazaProgramare(role, name, surname);
                askToReturnToMainMenu();
                break;
            case 3:
                system("cls");
                vizualizareOferte();
                askToReturnToMainMenu();
                break;
            case 4:
                system("cls");
                adaugaOferta();
                askToReturnToMainMenu();
                break;
            case 5:
                system("cls");
                stergeOferta();
                askToReturnToMainMenu();
                break;
            case 6:
                cout << "Iesire din aplicatie.\n";
                break;
            default:
                cout << "Optiune invalida. Te rog sa alegi o optiune valida.\n";
                break;
            }
        }
        while (choice != 6);
    }
    else
    {
        cout << "Rol invalid. Te rog sa introduci 'client' sau 'manager' ca prim argument.\n";
    }
}

Salon::Salon(const std::string& r, const std::string& n, const std::string& s)
    : role(r), name(n), surname(s)
{

}

void Salon::askToReturnToMainMenu()
{

    cout << "\nDoriti sa reveniti la meniul principal sau sa iesiti din aplicatie? (M - Meniu principal, X - Iesire): ";
    char response;
    cin >> response;
    system("cls");
    if (response == 'X' || response == 'x')
    {

        cout << "Va multumim. La revedere!\n";
        exit(0);
    }
}


