#include <iostream>
#include <string>
#include <cstdio>
#include <queue>
#include <regex>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

void set_bit(int &n, int &m, int i, int j);

int main() {
    int n = 0x1000, m = 0x13;
    set_bit(n, m, 2, 6);
    return 0;
}

void set_bit(int &n, int &m, int i, int j) {
    printf("%x %x\n", n, m);
    for (int k = 0; k <= j - i; k++) {
        if (((m >> k) & 1) == 0) n &= (~(1 << (i + k)));
        else n |= (1 << (i + k));
    }
    printf("%x %x\n", n, m);
}


