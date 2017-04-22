class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) {
            return 0;
        }
        vector<int> res{0};
        res.reserve(n+1);
        while (res.size() <= n) {
            int m = res.size();
            int count = INT_MAX;
            for (int i = 1; i * i <= m; i++) {
                count = min(count, res[m - i * i] + 1);
            }
            res.push_back(count);
        }
        return res[n];
    }
};
