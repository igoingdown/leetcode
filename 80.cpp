class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for (int end = 0, count = 0; end < nums.size(); end++) {
            if (end == 0 || nums[end] == nums[end - 1]) count++;
            else count = 1;
            if (count == 1 || count == 2) nums[len++] = nums[end];
        }
        return len;
    }
};