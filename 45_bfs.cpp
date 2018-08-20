class Solution {
public:
    int jump(vector<int>& nums) {
        int layer = 0, cur_max = 0, next_max = 0, i = 0, n = nums.size();
        if (n < 2) return 0;
        while (i <= cur_max) {
            layer++;
            while (i <= cur_max && i < n) {
                next_max = max(next_max, nums[i] + i);
                if (next_max >= n - 1) return layer;
                i++;
            }
            cur_max = next_max;
        }
        return 0;
    }
};