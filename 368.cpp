class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> counters(nums.size(), 0);
        vector<int> parent(nums.size(), 0);
        int m = 0, mi = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] % nums[i] == 0 && counters[i] < counters[j] + 1) {
                    counters[i] = counters[j] + 1;
                    parent[i] = j;
                    if (m < counters[i]) {
                        m = counters[i];
                        mi = i;
                    }
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < m; i++) {
            res.push_back(nums[mi]);
            mi = parent[mi];
        }
        return res;
    }
};
