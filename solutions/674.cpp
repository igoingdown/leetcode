class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() < 1) {
            return 0;
        }
        int res = INT_MIN, tmp = 0;
        for (int i = 0; i < nums.size(); i++) {
            tmp = i == 0 ? 1 : (nums[i] > nums[i - 1] ? tmp + 1 : 1);
            res = max(tmp, res);
        }
        return res;
    }
};