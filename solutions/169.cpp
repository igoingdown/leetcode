class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i, j, count;
        for (i = 0, j = 0, count = 0; j < nums.size(); j++) {
            if (nums[j] == nums[i]) count++;
            else if (count > 0) count--;
            else {
                i = j; count++;
            }
        }
        return nums[i];
    }
};