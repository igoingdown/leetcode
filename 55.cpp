class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), max_reach = 0, i = 0;
        while (i < n && i <= max_reach) {
            max_reach = max(max_reach, i + nums[i]);
            i++;
        }
        return i == n;
    }
};