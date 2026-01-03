#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(string &a, int i, string &b, int j, string &path, vector<string> &res);
vector<string> combine(string &a, string &b);

int main() {
	string a, b;
	cin >> a >> b;
	for (string &s : combine(a, b)) cout << s << endl;
	return 0;
}

vector<string> combine(string &a, string &b) {
	vector<string> res;
	string path;
	dfs(a, 0, b, 0, path, res);
	return res;
}

void dfs(string &a, int i, string &b, int j, string &path, vector<string> &res) {
	if (i == a.size()) {
		res.push_back(path + b.substr(j)); return;
	}
	if (j == b.size()) {
		res.push_back(path + a.substr(i)); return;
	}
	path += a[i]; dfs(a, i + 1, b, j, path, res); path.pop_back();
	path += b[j]; dfs(a, i, b, j + 1, path, res); path.pop_back();
}