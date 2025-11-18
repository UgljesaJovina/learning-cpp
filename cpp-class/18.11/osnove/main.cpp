#include "imeKlase.hpp"

#include <iostream>

using namespace std;

/* 
pri kompajliranju ovakvog projekta sa vise fajlova, moze se koristiti komanda
g++ *.cpp

zvezdica znaci bilo sta (ili nista), ispraceno sa '.cpp'
*/

int main() {
    ImeKlase k1;
    ImeKlase k2(1, 1900);
    ImeKlase k3(2, 384.4);

    ImeKlase k4(k3);

    cout << k1.getId() << endl;
    cout << k2.getStanje() << endl;
    cout << k3.asd() << endl;

    return 0;
}