#include "rerna.hpp"
#include <iostream>

using namespace std;

void ispisiRernu(const Rerna& r) {
    cout << "Temperatura rerne: " << r.getTemperatura() << endl;
    cout << "Stanje rerne: ";
    switch(r.getTrenutnoStanje()) {
        case ISKLJUCENA: cout << "iskljucena" << endl; break;
        case UKLJUCENA: cout << "ukljucena" << endl; break;
        case POKVARENA: cout << "pokvarena" << endl; break;
        default: cout << "why can't we live forever? i don't know" << endl; break;
    }
}

int meni() { return -1; }

int main() {
    Rerna r;
    
    ispisiRernu(r);
    
    r.ukljuci();
    
    ispisiRernu(r);

    return 0;
}