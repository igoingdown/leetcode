#include <iostream>
#include <string>
#include <regex>

using namespace std;


bool is_num(string &s);


int main() {
    string s; cin >> s;
    if (is_num(s)) cout << "Y" << endl;
    else cout << "N" << endl;
    return 0;
}

bool is_num(string &s) {
    int i = 0, l = s.size(), j = l - 1;
    while (i < s.size() && s[i] == ' ') i++;
    while (j > 0 && s[j] == ' ') j--;
    if (i > j) return false;
    s = s.substr(i, j - i + 1);
    regex e("^([\\+\\-])?((\\d+(\\.\\d*)?)|(\\.\\d+))(e([\\+\\-]?\\d+))?$");
    return regex_match(s.begin(), s.end(), e);
}
