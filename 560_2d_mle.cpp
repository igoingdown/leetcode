class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        if (n < 1) return res;
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
            if (dp[i][i] == k) res++;
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = dp[i][j - 1] + nums[j];
                if (dp[i][j] == k) res++;
            }
        }
        return res;
    }
};