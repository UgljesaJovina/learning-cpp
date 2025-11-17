/*
    korisnik unosi borjeve, naci najveci pozitivan
*/

#include <iostream>

using namespace std;

int main() {
    int max = 0;

    do {
        int x;
        cout << "Unesite broj: ";
        cin >> x;
        if (x == 0) break;
        if (x > max) max = x;
    } while (true);

    if (max == 0) cout << "Nije unet ni jedan pozitivan broj" << endl;
    else cout << "Najveci unet broj je: " << max << endl;

    return 0;
}