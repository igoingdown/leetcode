#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool isNumber(string s);

int main() {
	if (isNumber("1.0")) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}


bool isNumber(string s) {
    int i = 0, j = s.size();
    if (j == 0) return false;
    for (; s[i] == ' '; i++);
    for (j--; s[j] == ' '; j--);
    s = s.substr(i, j - i + 1);
    regex e("^([\\+\\-])?((\\d+(\\.\\d*)?)|(\\.\\d+))(e([\\+\\-]?\\d+))?$");
    return regex_match(s.begin(), s.end(), e);
}