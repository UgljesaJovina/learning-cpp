/*
    funkcija za izracunavanje svote novca za kupovinu karata za bioskop
    dva parametra, broj i cena, cene default = 50
*/

#include <iostream>

using namespace std;

int izracunajCenu(int brojKarata, int cenaKarte = 50) {
    return brojKarata * cenaKarte;
}

int main() {
    int brojKarata, cenaKarte;
    
    cout << "Unesite broj karata: ";
    cin >> brojKarata;

    if (brojKarata <= 0) {
        cout << "Broj karata mora biti pozitivan!" << endl;
        return 1;
    }

    cout << "Unesite cenu karte: ";
    cin >> cenaKarte;

    int izracunataCena;

    if (cenaKarte < 0) izracunataCena = izracunajCenu(brojKarata);
    else izracunataCena = izracunajCenu(brojKarata, cenaKarte);

    cout << "Potrebno " << izracunataCena << " dinara da bi se kupile karte";
}