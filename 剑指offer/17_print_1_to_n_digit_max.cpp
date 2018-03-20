#include <string>
#include <iostream>
#include <vector>

using namespace std;

void dfs(string& num, int n);
void print_num(string &num);
void print_nums(int n);

int main() {
	int n; cin >> n;
	print_nums(n);
	return 0;
}

void print_nums(int n) {
	string s;
	dfs(s, n);
}

void dfs(string &s, int n) {
	if (s.size() == n) {
		print_num(s); return;
	}
	for (int i = 0; i <= 9; i++) {
		s += ('0' + i);
		dfs(s, n);
		s.pop_back();
	}
}


void print_num(string &s) {
	int i = 0;
	while (i < s.size() && s[i] == '0') ++i;
	if (i < s.size()) cout << s.substr(i) << endl;
}

