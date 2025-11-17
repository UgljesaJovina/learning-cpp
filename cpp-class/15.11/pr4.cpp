/*
    napraviti dinamicki alociran niz i:
        1. funkciju koja unosi elemente
        2. funkciju koja stampa niz
        3. funkciju koja ga sortira sa opcionalna tri argumenta (treci ce da bude vrsta sortiranja)
*/

#include <iostream>

using namespace std;

enum VRSTA_SORTIRANJA { RASTUCE, OPADAJUCE };

void unosElemenata(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Unesite " << i + 1 << ". element niza: ";
        cin >> arr[i];
    }
}

void ispis(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Element indeksa " << i + 1 << " je " << arr[i] << endl;
    }
}

void sortiraj(int *arr, int n, VRSTA_SORTIRANJA srt = RASTUCE) {
    switch (srt)
    {
    case RASTUCE:
        for (int i = 0; i < n - 1; i++) {
            for (int j = i+1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        break;
    case OPADAJUCE:
        for (int i = 0; i < n - 1; i++) {
            for (int j = i+1; j < n; j++) {
                if (arr[i] < arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        break;
    default:
        break;
    }
}

int main() {
    int n;
    cout << "Unesite broj elemenata niza: ";
    cin >> n;

    if (n <= 0) {
        cout << "n mora biti pozitivan broj" << endl;
        return 1;
    }

    int *arr = new int[n];
    
    if (arr == NULL) {
        cout << "Alokacija neuspela" << endl;
        return 1;
    }

    unosElemenata(arr, n);
    cout << endl;
    ispis(arr, n);
    cout << endl;

    sortiraj(arr, n, OPADAJUCE);
    ispis(arr, n);
}