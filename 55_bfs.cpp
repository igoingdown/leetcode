class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return true;
        int cur_max = 0, next_max = 0, i = 0;
        while (i <= cur_max) {
            while (i <= cur_max && i < n) {
                next_max = max(next_max, i + nums[i]);
                if (next_max >= n - 1) return true;
                i++;
            }
            cur_max = next_max;
        }
        return false;
    }
};