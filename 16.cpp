class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        if (n <= 3) {
            for (auto n: nums) {
                res += n;
            }
            return res;
        }
        if (nums[0] + nums[1] + nums[2] >= target) {
            return nums[0] + nums[1] + nums[2];
        }
        if (nums[n - 1] + nums[n - 2] + nums[n - 3] <= target) {
            return nums[n - 1] + nums[n - 2] + nums[n - 3];
        }
        res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                abs(res - target) < abs(sum - target) ? res : res = sum;
                if (res == target) {
                    return res;
                }
                sum < target ? left++ : right--;
            }
        }
        return res;
    }
};
