#include <iostream>
#include <vector>

using namespace std;

int main() {
	return 0;
}

vector<int> longestDownPath(vector<vector<int>> &matrix) {
	int m = matrix.size(), n = matrix[0].size();
	vector<int> res;
	vector<vector<bool>> visit(m, vector<bool> (n, false));
	dfs(matrix, res, visit, 0, 0, m, n);
	return res;
}
void dfs(vector<vector<int>> &matrix, vector<int> &path, vector<vector<bool>> &visit, int x, int y, int m, int n) {
	if (x < 0 || x >= m || y < 0 || y >= n || visit[x][y]) {
		res = res.size() < path.size() ? path : res; return;
	}
	vector<int> bias = {1, 0, -1, 0, 1};
	visit[x][y] = true; path.push_back(matrix[x][y]);
	for (int i = 0; i < 4; i++) {
		int r = x + bias[i], c = y + bias[i + 1];
		if (r >= 0 && r < m && c >= 0 && c < n && matrix[x][y] >= matrix[r][c]) dfs(matrix, path, visit, r, c, m, n);
	}
	visit[x][y] = false; path.pop_back();
}

