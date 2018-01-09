#include <sstream>
#include <limits>
#include <iostream>
#include <string>

using namespace std;
int calculate(string s);
int main(void) {
    string s = "0 - 2147483647";
    cout << calculate(s) << endl;
}

int calculate(string s) {
    long long res = 0, tmp = 0;
    istringstream in("+" + s + "+");
    char op;
    while (in >> op) {
        if (op == '+' || op == '-') {
            res += tmp;
            in >> tmp;
            tmp *= (op == '+' ? 1 : -1);
        } else if (op == '*' || op == '/') {
            int t;
            in >> t;
            if (op == '*') tmp *= t;
            else tmp /= t;
        }
    }
    return res;
}
