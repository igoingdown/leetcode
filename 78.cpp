class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1, vector<int>());
        for (auto n : nums) {
            int s = res.size();
            for (int i = 0; i < s; i++) {
                vector<int> tmp(res[i]);
                tmp.push_back(n);
                res.push_back(tmp);
            }
        }
        return res;
    }
};