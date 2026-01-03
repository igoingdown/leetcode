#include<iostream>
#include<cmath>
#include<map>
#include<string>

using namespace std;

int main() {

    map<int, string> m {
        {1, "I"},
        {2, "II"},
        {3, "III"},
        {4, "IV"},
        {5, "V"},
        {6, "VI"},
        {7, "VII"},
        {8, "VIII"},
        {9, "IX"},
        {10, "X"},
        {20, "XX"},
        {30, "XXX"},
        {40, "XL"},
        {50, "L"},
        {60, "LX"},
        {70, "LXX"},
        {80, "LXXX"},
        {90, "XC"},
        {100, "C"},
        {200, "CC"},
        {300, "CCC"},
        {400, "CD"},
        {500, "D"},
        {600, "DC"},
        {700, "DCC"},
        {800, "DCCC"},
        {900, "CM"},
        {1000, "M"},
    };
    int num = 1994;
    string res;
    for (int i = 3; i >= 0; i--) {
        int base = pow(10, i);
        int cur = num / base * base;
        if (cur != 0) {
            res += m[cur];
            num -= cur;
        }
    }
    std::cout << res << std::endl;
    return 0;
}