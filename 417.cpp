class Solution {
public:
    vector<pair<int, int>> res;
    int m, n;
    vector<vector<int>> visited;
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        res.resize(0);
        m = matrix.size();
        if (m < 1) return res;
        n = matrix[0].size();
        visited.resize(m, vector<int>(n ,0));
        for (int i = 0; i< m; i++) {
            dfs(i, 0, matrix, INT_MIN, 1);
            dfs(i, n - 1, matrix, INT_MIN, 2);
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j, matrix, INT_MIN, 1);
            dfs(m - 1, j, matrix, INT_MIN, 2);
        }
        return res;
    }
    
    
    void dfs(int i, int j, vector<vector<int>>& matrix, int preHeight, int mark){
        if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] < preHeight || (mark & visited[i][j]) == mark) return;
        visited[i][j] |= mark;
        if (visited[i][j] == 3) res.push_back(make_pair(i, j));
        int bias[5] = {0, 1, 0, -1, 0};
        for (int k = 0; k < 4; k++) {
            int r = i + bias[k], c = j + bias[k + 1];
            dfs(r, c, matrix, matrix[i][j], visited[i][j]);
        }
    }
};