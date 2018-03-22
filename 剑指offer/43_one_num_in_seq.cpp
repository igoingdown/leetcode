#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int one_num(int n);
int one_num_recursion(const string &s, int start);

int main() {
	int n;
	while (cin >> n) {
		cout << "res : " << one_num(n) << endl;
	}
	return 0;
}

int one_num(int n) {
	string s = to_string(n);
	return one_num_recursion(s, 0);
}

int one_num_recursion(const string &s, int start) {
	int res = 0;
	if (start == s.size()) return res;
	if (s[start] == '0') return one_num_recursion(s, start + 1);
	if (s[start] > '1') res += pow(10, s.size() - start - 1);
	else {
		res++;
		if (start + 1 < s.size()) res += stoi(s.substr(start + 1));
	}
	res += (s.size() - start - 1 > 0) ? (s.size() - start - 1) * pow(10, s.size() - start - 2) * (s[start] - '0') : 0;
	return res + one_num_recursion(s, start + 1);
}

