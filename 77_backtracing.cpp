class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(res, tmp, n, 1, k);
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, vector<int> tmp, int n, int s, int emp) {
        if (emp == 0) {
            res.push_back(tmp);
            return;
        }
        for (int i = s; i <= n; i++) {
            tmp.push_back(i);
            backtrack(res, tmp, n, i + 1, emp - 1);
            tmp.pop_back();
        }
    }
};