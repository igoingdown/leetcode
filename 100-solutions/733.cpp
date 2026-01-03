class Solution {
private:
    int m, n, oldColor;
    int bias[5] = {1, 0, -1, 0, 1};
    void dfs (vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (sr < 0 || sr >= m || sc < 0 || sc > n || image[sr][sc] != oldColor) return;
        image[sr][sc] = -1;
        for (int i = 0; i < 4; i++) {
            int new_r = sr + bias[i], new_c = sc + bias[i + 1];
            dfs(image, new_r, new_c, newColor);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size(), n = image[0].size();
        oldColor = image[sr][sc];
        dfs(image, sr, sc, newColor);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (image[i][j] == -1) image[i][j] = newColor;
            }
        }
        return image;
    }
};