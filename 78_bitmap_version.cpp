class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> emp(0);
        // sort(nums.begin(), nums.end());
        vector<vector<int>> res(pow(2, nums.size()), emp);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < res.size(); j++) {
                if ((j >> i) & 1) {
                    res[j].push_back(nums[i]);
                }
            }
        }
        return res;
    }
};