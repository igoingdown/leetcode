#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool existPath(const vector<vector<char>> &matrix, const string &str);
bool dfs(const vector<vector<char>> &matrix, const string& str, vector<vector<bool>> &visit, const vector<int> &bias, int pos, int row, int col);

int main() {
	vector<vector<char>> matrix = {{'a', 'b', 't', 'g'}, {'c', 'f', 'c', 's'}, {'j', 'd', 'e', 'h'}};
	string s;
	cin >> s;
	if (existPath(matrix, s)) cout << "Y" << endl;
	else cout << "N" << endl;
	return 0;
}

bool existPath(const vector<vector<char>> &matrix, const string &str) {
	if (str.size() == 0) return true;
	int m = matrix.size(), n;
	if (m == 0) return false;
	n = matrix[0].size();
	if (n == 0) return false;
	int pos = 0;
	vector<vector<bool>> visit(m, vector<bool>(n));
	vector<int> bias = {1, 0, -1, 0, 1};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (dfs(matrix, str, visit, bias, pos, i, j)) return true;
		}
	}
	return false;
}


bool dfs(const vector<vector<char>> &matrix, const string& str, vector<vector<bool>> &visit, const vector<int> &bias, int pos, int row, int col) {
	if (pos >= str.size()) return true;
	if (row >= matrix.size() || row < 0 || col >= matrix[0].size() || col < 0 || str[pos] != matrix[row][col]) return false;
	if (!visit[row][col]) {
		visit[row][col] = true;
		for (int i = 0; i < 4; i++) {
			int x = row + bias[i], y = col + bias[i + 1];
			if (dfs(matrix, str, visit, bias, pos + 1, x, y)) return true;
		}
		visit[row][col] = false;
	}
	return false;
}

