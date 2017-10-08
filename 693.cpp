#include <iostream>

using namespace std;
bool hasAlternatingBits(int n);

int main(void) {
    if (hasAlternatingBits(5)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}


bool hasAlternatingBits(int n) {
    if (n < 3) {
        return true;
    }
    int ex = n % 2;
    n >>= 1;
    while (n) {
        // cout << n << endl;
        int b = n % 2;
        // cout << b << " " << ex << endl;
        if (!(b ^ ex)) {
            return false;
        }
        ex = b;
        n >>= 1;
    }
    return true;
}