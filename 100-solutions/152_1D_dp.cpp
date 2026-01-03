class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), ans = nums[0];
        vector<int> f_max(n), f_min(n);
        f_max[0] = nums[0];
        f_min[0] = nums[0];
        for (int i = 1; i < n; i++) {
            f_max[i] = max(nums[i], max(f_max[i - 1] * nums[i], f_min[i - 1] * nums[i]));
            f_min[i] = min(nums[i], min(f_max[i - 1] * nums[i], f_min[i - 1] * nums[i]));
            ans = max(f_max[i], ans);
        }
        return ans;
    }
};