#include <iostream>
#include <climits>
#include <array>

using namespace std;

int main() {
    int a[5];
    for (int i = 0; i < 5; i++) {
       a[i]  = i;
    }
    int *ptr = a;
    *((char *)ptr + 8) = 0x10;
    *((char *)ptr + 9) = 0xff;
    *((char *)ptr + 10) = 0xee;
    *((char *)ptr + 11) = 0xaa;

    cout << hex;
    cout << ptr << endl;
    for (int i = 0; i < 5; i++) {
        cout << a[i] << endl;
    }

    array<int,5> b{100,128,32};
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << endl;
    }
}

