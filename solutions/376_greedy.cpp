class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        bool allEqual = true;
        int i = 1;
        for (; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                allEqual = false;
                break;
            }
        }
        if (allEqual) {
            return 1;
        }
        bool requireBig = nums[i] < nums[0];
        vector<int> series(2, nums[0]);
        series[1] = nums[i];
        for (i++; i < n; i++) {
            if (requireBig) {
                if (series.back() < nums[i]) {
                    series.push_back(nums[i]);
                    requireBig = false;
                } else if (series.back() > nums[i]) {
                    series[series.size() - 1] = nums[i];
                }
            } else {
                if (series.back() > nums[i]) {
                    series.push_back(nums[i]);
                    requireBig = true;
                } else if (series.back() < nums[i]) {
                    series[series.size() - 1] = nums[i];
                }
            }
        }
        return series.size();
    }
};