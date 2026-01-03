class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int s = nums.size();
        if (s == 0) return -1;
        int max_index = 0;
        for (int i = 1; i < nums.size(); i++) {
            max_index = nums[i] > nums[max_index] ? i : max_index;
        }
        int c = 0;
        for (int n : nums) {
            if (nums[max_index] / 2 >= n) c++;
        }
        return c >= s - 1 ? max_index : -1; 
    }
};