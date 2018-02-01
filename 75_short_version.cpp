class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), red_i = 0, blue_i = n - 1;
        for (int i = 0; i <= blue_i; i++) {
            while (nums[i] == 2 && i < blue_i) swap(nums[i], nums[blue_i--]);
            while (nums[i] == 0 && i > red_i) swap(nums[i], nums[red_i++]);
        }
    }
};