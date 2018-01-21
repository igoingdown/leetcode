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
    int s1 = num1.size(), s2 = num2.size(), max_len = s1 + s2, c = 0;
    if (max_len == 0) return "";
    string res(max_len, '0');
    for (int i = 0; i < max_len; i++) {
        int bit_res = c;
        for (int j = 0; j <= i; j++) {
            if (j < s1 && i - j < s2) bit_res += (num1[s1 - 1 - j] - '0') * (num2[s2 - 1 - i + j] - '0');
        }
        c = bit_res / 10;
        res[max_len - 1 - i] = char(bit_res % 10 + '0');
    }
    int pos = 0;
    while (res[pos] == '0') pos++;
    return pos == res.size() ? "0" : res.substr(pos);
}
