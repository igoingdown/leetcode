class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] <= n && nums[i] > 0 && i != nums[i] - 1 && nums[nums[i] - 1] != nums[i]) swap(nums[nums[i] - 1], nums[i]);
        }
        int res = 1;
        while (res <= n && nums[res - 1] == res) res++;
        return res;
    }
};