class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return true;
        int cur_max = 0, next_max = 0, i = 0;
        while (cur_max - i + 1 > 0) {
            for (; i <= cur_max; i++) {
                next_max = max(next_max, i + nums[i]);
                if (next_max >= n - 1) return true;
            }
            cur_max = next_max;
        }
        return false;
    }
};