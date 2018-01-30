class Solution {
public:
    int jump(vector<int>& nums) {
        int layer = 0, cur_max = 0, next_max = 0, i = 0, n = nums.size();
        if (n < 2) return 0;
        while (cur_max - i + 1 > 0) {
            layer++;
            for (; i <= cur_max && i < n; i++) {
                next_max = max(next_max, nums[i] + i);
                if (next_max >= n - 1) return layer;
            }
            cur_max = next_max;
        }
        return 0;
    }
};