#include <iostream>
#include <string>


using namespace std;

int numDecodings(string s);
bool valid(char c);
bool valid(char a, char b);

int main(void) {
    string s("100");
    cout << numDecodings(s) << endl;
    return 0;
}

int numDecodings(string s) {
    if (s.size() == 0 || s[0] == '0') {
        return 0;
    }
    if (s.size() == 1) {
        return 1;
    }
    int m = s.size(), fn_1 = 1, fn_2 = 1;
    for (int i = 1; i < m; i++) {
        int temp = fn_1;
        if (valid(s[i]) && valid(s[i - 1], s[i])) {
            fn_1 += fn_2;
        } else if (!valid(s[i]) && !valid(s[i - 1], s[i])) {
            return 0;
        } else if (!valid(s[i]) && valid(s[i - 1], s[i])) {
            fn_1 = fn_2;
        } 
        fn_2 = temp;
    }
    return fn_1;
}

bool valid(char c) {
    return c != '0';
}
bool valid(char a, char b) {
    return a == '1' || (a == '2' && b <= '6');
}