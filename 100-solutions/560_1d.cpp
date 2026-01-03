class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        if (n < 1) return res;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
            if (dp[i] == k) res++;
            for (int j = i + 1; j < n; j++) {
                dp[j] = dp[j - 1] + nums[j];
                if (dp[j] == k) res++;
            }
        }
        return res;
    }
};