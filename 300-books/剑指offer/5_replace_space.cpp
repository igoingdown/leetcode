#include <iostream>
#include <string>

using namespace std;

void repalce_space(string &s);

int main() {
	string s("afehu fehu  ");
	repalce_space(s);
	cout << s << endl;
	return 0;
}


void repalce_space(string &s) {
	int count = 0, i = s.size(), j;
	for (char c : s) {
		if (c == ' ') count++;
	}
	j = i + count * 2; s.resize(j); 
	while (i > 0) {
		--i;
		if (s[i] == ' ') {
			s[--j] = '0'; s[--j] = '2'; s[--j] = '%';
		} else s[--j] = s[i];
	}
}