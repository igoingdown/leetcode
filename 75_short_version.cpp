class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroIndex = 0, twoIndex = nums.size() - 1;
        for (int i = 0; i <= twoIndex; i++) {
            while (nums[i] == 2 && i < twoIndex) {
                swap(nums[i], nums[twoIndex--]);
            }
            while (nums[i] == 0 && i > zeroIndex) {
                swap(nums[i], nums[zeroIndex++]);
            }
        }
    }
};