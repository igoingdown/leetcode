class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i;
        if (n < 2) return;
        for (i = n - 2; i >= 0 && nums[i] >= nums[i + 1]; i--);
        reverse(nums.begin() + i + 1, nums.end());
        if (i == -1) return;
        auto iter = upper_bound(nums.begin() + i + 1, nums.end(), nums[i]);
        swap(nums[i], *iter);
    }
};