class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 1) {
            return 0;
        } else if (n < 2) {
            return nums[0];
        }
        int e = 0, i = 0;
        for (int x : nums) {
            int e1 = e, i1 = i;
            i = e1 + x;
            e = max(i1, e1);
        }
        return max(i, e);
    }
};