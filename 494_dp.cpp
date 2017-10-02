class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        long long t = accumulate(nums.begin(), nums.end(), 0);
        if (S > t || S < -t) {
            return 0;
        }
        vector<int> d(2 * t + 1, 0), n(2 * t + 1, 0), *dp = &d, *next = &n;
        dp->at(t) = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 2 * t + 1; j++) {
                if (dp->at(j) > 0) {
                    next->at(j + nums[i]) += dp->at(j);
                    next->at(j - nums[i]) += dp->at(j);
                }
            }
            swap(dp, next);
            next->clear();
            next->resize(2 * t + 1, 0);
        }
        return dp->at(t + S);
    }
};