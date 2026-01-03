#include <iostream>
#include <stack>
#include <vector>

using namespace std;


bool is_leagal(const vector<int> &a, const vector<int> &b);
bool dfs(const vector<int> &a, int i, const vector<int> &b, int j, stack<int> &s);

int main() {
	vector<int> a = {1, 2, 3, 4, 5}, b = {4, 3, 5, 1, 2};
	if (is_leagal(a, b)) cout << "Y" << endl;
	else cout << "N" << endl;
	return 0;
}

bool is_leagal(const vector<int> &a, const vector<int> &b) {
	if (a.size() != b.size()) return false;
	stack<int> s;
	return dfs(a, 0,b, 0, s);
}

bool dfs(const vector<int> &a, int i, const vector<int> &b, int j, stack<int> &s) {
	if (j == b.size()) return true;
	if (!s.empty() && s.top() == b[j]) {
		s.pop();
		if (dfs(a, i, b, j + 1, s)) return true;
		s.push(b[j]);
	}
	for (int pos = i; pos < a.size(); pos++) {
		s.push(a[pos]);
		if (dfs(a, pos + 1, b, j, s)) return true;
	}
	return false;
}

