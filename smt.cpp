#include <iostream>

using namespace std;

int main() {
    int x = 15;
    int *px = &x;
    int **ppx = &px;

    cout << x << endl << px << endl << *px << endl << &x 
    << endl << ppx << endl << *ppx << endl << &ppx << endl;

    return 0;
}