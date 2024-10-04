#ifndef SALON_H_INCLUDED
#define SALON_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Salon {
private:
    string role;
    string name;
    string surname;


public:
    Salon(const string& r, const string& n, const string& s);

    void askToReturnToMainMenu();
    void displayClientMenu();
    void displayManagerMenu();
    void run();


};


#endif // SALON_H_INCLUDED
