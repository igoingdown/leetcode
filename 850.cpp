class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int res = 0, mod = 1e9 + 7;
        vector<int> X, Y;
        for (auto rec : rectangles) {
            X.push_back(rec[0]);
            X.push_back(rec[2]);
            Y.push_back(rec[1]);
            Y.push_back(rec[3]);
        }
        sort(X.begin(), X.end());
        X.erase(unique(X.begin(), X.end()), X.end());
        sort(Y.begin(), Y.end());
        Y.erase(unique(Y.begin(), Y.end()), Y.end());
        vector<vector<bool>> visit(X.size(), vector<bool>(Y.size()));
        for (auto rec : rectangles) {
            int x1 = lower_bound(X.begin(), X.end(), rec[0]) - X.begin();
            int y1 = lower_bound(Y.begin(), Y.end(), rec[1]) - Y.begin();
            int x2 = lower_bound(X.begin(), X.end(), rec[2]) - X.begin();
            int y2 = lower_bound(Y.begin(), Y.end(), rec[3]) - Y.begin();
            for (int i = x1; i < x2; i++) {
                for (int j = y1; j < y2; j++) visit[i][j] = true;
            }
        }
        for (int i = 0; i < X.size(); i++) {
            for (int j = 0; j < Y.size(); j++) {
                if (visit[i][j]) res = (res + (long long)(X[i + 1] - X[i]) * (Y[j + 1] - Y[j])) % mod;
            }
        }
        return res;
    }
};