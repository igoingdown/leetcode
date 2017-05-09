#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int calculate(string s);

int main(void) {
  string s("1/2");
  cout << calculate(s) << endl;
  return 0;
}


int calculate(string s) {
    istringstream in('+' + s + '+');
    long long res = 0, term = 0;
    int n;
    char op;
    while (in >> op) {
        if (op == '+' || op == '-') {
            res += term;
            in >> term;
            term *= (op == '+' ? 1 : -1);
        } else {
            in >> n;
            if (op == '*') {
                term *= n;
            } else {
                term /= n;
            }
        }
    }
    return res;
}
