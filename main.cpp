#include "salon.h"
#include "oferte.h"
#include "programari.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <role> <nume> <prenume>\n";
        return 1;
    }

    string role = argv[1];
    string name = argv[2];
    string surname = argv[3];

    Salon salon(role, name, surname);
    salon.run();

    return 0;
}
