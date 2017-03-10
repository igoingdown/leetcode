class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] + nums[i + 1] + nums[i + 2] > target) {
                int sum = nums[i] + nums[i + 1] + nums[i + 2];
                abs(res - target) > abs(sum - target) ? res = sum : res;
                return res;
            }
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                abs(res - target) > abs(sum - target) ? res = sum : res;
                if (sum < target) {
                    l++;
                } else if (sum > target) {
                    r--;
                } else {
                    return res;
                }
            }
        }
        return res;
    }
};
