class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size(), res = 0;
        if (n < 2) return res;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            res = max(res, nums[i] - nums[i - 1]);
        }
        return res;
    }
};