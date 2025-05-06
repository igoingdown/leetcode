class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int res = nums[0], dp=nums[0];
            for (int i = 1; i < nums.size(); i++) {
                res = max(max(res, nums[i]), nums[i] + dp);
                dp = max(dp + nums[i], nums[i]);
            }
            return res;
        }
    };