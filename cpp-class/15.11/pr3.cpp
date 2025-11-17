/*
    korisnik unese n, napisati funkciju koja da rezultat sqrt(1) + sqrt(2) + ... + sqrt(n)
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float f(int n) {
    if (n <= 0) return -1;
    float rez = 0;
    for (int i = 1; i <= n; i++) {
        rez += sqrt(i);
    }
    return rez;
}

int main() {
    int n;
    cout << "Unesite n: ";
    cin >> n;

    float rez = f(n);

    if (rez == -1) {
        cout << "Los unos" << endl;
        return 1;
    }

    cout << "Rezultat: " << setprecision(2) << fixed << rez << endl;

    return 0;
}


/*
    druga implementacija ovog programa bi bila bez setprecision da kad se dobije rezultat od funkcije f
    pomnozimo rez sa 100, uradimo round da uklonimo decimalni deo i onda podelimo sa 100 da nam ostanu dve decimale:

    float rez = f(n);
    rez = round(rez * 100) / 100;
    cout << rez << endl;

    (10.4838723 pretvori u 1048.38723, odsece posle tacke i onda vrati u 10.48)
*/