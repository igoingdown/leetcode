class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        });
        vector<int> widths;
        widths.reserve(envelopes.size());
        for (auto &p : envelopes) widths.push_back(p.second);
        return LIS(widths);
    }
    
    int LIS(vector<int> &nums) {
        vector<int> dp;
        dp.reserve(nums.size());
        int res = 0;
        for (int n : nums) {
            if ((dp.size() > 0 && n > dp.back()) || dp.size() == 0) dp.push_back(n);
            else dp[BS(dp, n)] = n;
            res = res > dp.size() ? res : dp.size();
        }
        return res;
    }
    
    int BS(vector<int> &nums, int t) {
        int low = 0, high = nums.size() - 1, mid;
        while (low < high) {
            mid = low + ((high - low) >> 1);
            if (nums[mid] < t) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};