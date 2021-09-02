#include <iostream>
#include <string>

using namespace std;

string shortestSubstring(string s);

int main() {
    string s = "abcabc";
    cout << shortestSubstring(s) << endl;
    return 0;
}

string shortestSubstring(string &s) {
    for (int i = 1; i <= s.size(); i++) {
        string p = s.substr(0, i);
        int j = 0;
        while (j < s.size() && s[j] == p[j % i]) j++;
        if (j == s.size()) return p;
    }
    return s;
}