class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 1) {
            return 0;
        } else if (n < 2) {
            return nums[0];
        }
        vector<int> r(n, 0);
        r[0] = nums[0];
        r[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            r[i] = max(r[i - 1], r[i - 2] + nums[i]);
        }
        return r[n - 1];
    }
};