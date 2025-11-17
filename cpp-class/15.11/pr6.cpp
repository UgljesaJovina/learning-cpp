/*
    napisati funkciju koja na osnovu primljene godine odredjuje da li je godina prestupna ili ne
    prestupna je ako je deljiva sa 4, osim ako je deljiva sa 100 a ne 400
*/

#include <iostream>

using namespace std;

bool prestupna(int godina) {
    if (godina % 100 == 0 && godina % 400 != 0) return false;
    else if (godina % 4 == 0) return true;
    else return false;
}

int main() {
    int godina;

    cout << "Unesite godinu: ";
    cin >> godina;

    if (godina <= 0) {
        cout << "Los unos" << endl;
        return 1;
    }

    if (prestupna(godina)) 
        cout << "Godina je prestupna" << endl;
    else 
        cout << "Godina nije prestupna" << endl;

    return 0;
}