/*
    korisnik unese n, naci sumu n unetih borjeva
*/

#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Unesti n: ";
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Unesite broj: ";
        cin >> x;
        sum += x;
    }
    cout << "Suma: " << sum << endl;
    return 0;
}