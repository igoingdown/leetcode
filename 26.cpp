class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        for (int i = 0, count = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] == nums[i - 1]) count++;
            else count = 1;
            if (count == 1) nums[l++] = nums[i];
        }
        return l;
    }
};