#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s);

int main() {
	if (isPalindrome("0P")) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}


bool isPalindrome(string s) {
    int l = s.size(), b = 0, e = l - 1;
    while (b < e) { 
        while (!isalnum(s[b])) b++;
        while (!isalnum(s[e])) e--;
        if (isupper(s[b])) s[b] += 'a' - 'A';
        if (isupper(s[e])) s[e] += 'a' - 'A';
        if (b < e && s[b] != s[e]) return false;
        b++; e--;
    }
    return true;
}