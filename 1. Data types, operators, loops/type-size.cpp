#include <iostream>
using namespace std;

int main()
{
    cout << "Size of short " << sizeof(short) << " bytes" << endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of unsigned: " << sizeof(unsigned) << " bytes" << endl;
    cout << "Size of long: " << sizeof(long) << " bytes" << endl;
    cout << "Size of long long: " << sizeof(long long) << " bytes" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of char: " << sizeof(char) << " byte" << endl;
    cout << "Size of wchar_t: " << sizeof(wchar_t) << " byte" << endl;
    cout << "Size of pointer: " << sizeof(void*) << " bytes" << endl;

    return 0;
}