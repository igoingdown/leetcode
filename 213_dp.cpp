class Solution {
private:
    int rob(vector<int>& nums, int s, int e) {
        int i = 0, j = 0;
        for (int k = s; k <= e; k++) {
            int i1 = i, j1 = j;
            i = j1 + nums[k];
            j = max(i1, j1);
        }
        return max(i, j);
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(rob(nums, 0, nums.size() - 2), rob(nums, 1, nums.size() - 1));
    }
};