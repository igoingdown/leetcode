class Solution {
private:
    int rob(const vector<int>& nums, int s, int e) {
        int n = e - s + 3;
        vector<int> dp(n);
        for (int i = 0; i < n - 2; i++) dp[i + 2] = max(dp[i + 1], dp[i] + nums[s + i]);
        return dp[n - 1];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) {
            return nums[0];
        }
        return max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }
};