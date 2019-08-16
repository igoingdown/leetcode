#include <iostream>
#include <string>
#include <vector>


using namespace std;

void permutations(const string &s);
void dfs(vector<int> &v, string &path, const string &s);

int main() {
	string s; cin >> s;
	permutations(s);
	return 0;
}


void permutations(const string &s) {
	vector<int> v(256);
	for (char c : s) v[c]++;
	string path = "";
	dfs(v, path, s);
}

void dfs(vector<int> &v, string &path, const string &s) {
	if (path.size() == s.size()) {
		cout << path << endl; return;
	}
	for (int i = 0; i < 256; i++) {
		if (v[i] > 0) {
			path += char(i); v[i]--;
			dfs(v, path, s);
			path.pop_back(); v[i]++;
		}
	}
}

