class Solution {
private:
    int dfs(vector<int>& nums, int t, int s) {
        if (t < 0) {
            return !t;
        }
        int res = 0;
        res += (t == 0 ? 1 : 0);
        for (int i = s; i < nums.size(); i++) {
            res += dfs(nums, t - nums[i], i + 1);
        }
        return res;
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        long long total = accumulate(nums.begin(), nums.end(), 0);
        long long t = total + S;
        if (t % 2) {
            return 0;
        }
        t /= 2;
        return dfs(nums, t, 0);
    }
};