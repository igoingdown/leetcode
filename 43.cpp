#include <iostream>
#include <vector>
#include <string>

using namespace std;

string multiply(string num1, string num2);


int main(int argc, char const *argv[]) {
  /* code */
  string s1(1, '9');
  string s2(2, '9');
  string res = multiply(s1, s2);
  cout << res << endl;
  return 0;
}

string multiply(string num1, string num2) {
    int s1 = num1.size(), s2 = num2.size();
    int maxLen = s1 + s2;
    int c = 0;
    string p(maxLen, '0');
    for (int i = 0; i < maxLen; i++) {
        int res = c;
        for (int j = 0; j <= i; j++) {
            if (j < s1 && i - j < s2) {
                res += (num1[s1 - 1 - j] - '0') * (num2[s2 - 1 - i + j] - '0');
            }
        }
        c = res / 10;
        res %= 10;
        p[maxLen - 1 - i] = char(res + '0');
    }
    int pos = 0;
    while (p[pos] == '0') {
        pos++;
    }
    p = p.substr(pos);
    if (p.size() == 0) {
        p += "0";
    }
    return p;
}
