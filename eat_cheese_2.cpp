#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <limits.h>

using namespace std;
int eatCheese(vector<vector<int>>& matrix);
void dfs(vector<pair<int, int>>& middle_points, vector<pair<int,int>>& points, 
	int& ans, vector<int>& path, vector<bool>& visited, vector<vector<int>>& dis);

int main() {
	int a[3] = {1, 0, 2};
	int b[3] = {1, 1, 0};
	int c[3] = {0, 2, 1};
	vector<int> v1(a, a + 3);
	std::vector<int> v2(b, b + 3);
	std::vector<int> v3(c, c + 3);
	vector<vector<int>> v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	cout << eatCheese(v) << endl;
	return 0;
}

int eatCheese(vector<vector<int>>& matrix) {
	int m = matrix.size(), n = matrix[0].size();
	vector<pair<int, int>> points;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == 2) points.push_back({i, j});
		}
	}
	points.push_back({0, 0});
	points.push_back({m - 1, n - 1});
	int s = points.size();
	vector<vector<int>> dis(s, vector<int>(s, INT_MAX));
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			if (i != j) dis[i][j] = bfs(matrix, i, j, s);
		}
	}
	vector<bool> visited(s - 2);
	vector<pair<int, int>> middle_points(points.begin(), points.begin() + s - 2);
	int ans = INT_MAX;
	dfs(middle_points, points, ans, path, visited, dis);
	return ans;
}


void dfs(vector<pair<int, int>>& middle_points, vector<pair<int,int>>& points, 
	int& ans, vector<int>& path, vector<bool>& visited, vector<vector<int>>& dis) {
	if (path.size() == middle_points.size()) {
		ans = min(ans, dis[middle_points.size()][path[0]] + sum + dis[path.back()][middle_points.size() + 1]);
		return;
	}
	path.push_back(start);
	for (int i = 0; i < middle_points.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			if (path.size() > 0) sum += dis[path.back()][i];
			path.push_back(i);
			dfs(middle_points, points, ans, path, visited, dis);
			path.pop_back();
			if (path.size() > 0) sum -= dis[path.back()][i];
			visited[i] = false;
		}
	}
}


int bfs(vector<vector<int>>& matrix, int b, int e, vector<pair<int, int>>& points) {
	queue<pair<int, int>> q, next;
	set<pair<int, int>> visited;
	q.push(b);
	visited.insert(b);
	int bias[5] = {1, 0, -1, 0, 1};
	int layer = 0;
	while (!q.empty()) {
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int x = cur.first + bias[i], y = cur.second + bias[i + 1];
				if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && visited.find({x, y}) == visited.end()) {
					if (x == e.first && y == e.second) return layer + 1;
					else next.push({x, y});
				}
			}
		}
		swap(q, next);
		layer++;
	}
	return INT_MAX;
}