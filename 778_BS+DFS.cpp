class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        if (N < 2) return 0; 
        int low = 0, high = 0, mid;
        for (vector<int>& row : grid) {
            for (int& num : row) high = max(num, high);
        }
        vector<vector<int>> visited(grid);
        vector<int> bias = {0,1,0,-1,0};
        while (low < high) {
            mid = low + ((high - low) >> 1);
            for (vector<int>& row : visited) {
                for (int& num : row) num = 0;
            }
            visited[0][0] = 1;
            if (dfs(grid, N, mid, visited, bias, 0, 0, grid[0][0])) high = mid;
            else low = mid + 1;
        }
        return low;
    }
    
    bool dfs(vector<vector<int>>& grid, int N, int t, vector<vector<int>>& visited, vector<int>& bias, int x, int y, int cur) {
        if (x == N - 1 && y == N - 1) return true;
        for (int i = 0; i < 4; i++) {
            int newX = x + bias[i], newY = y + bias[i + 1];
            if (newX < N && newX >= 0 && newY < N && newY >= 0 && !visited[newX][newY] && grid[newX][newY] <= t && t >= cur) {
                visited[newX][newY] = 1;
                if (dfs(grid, N, t, visited, bias, newX, newY, max(cur, grid[newX][newY]))) return true;
            }
        }
        return false;
    }
};