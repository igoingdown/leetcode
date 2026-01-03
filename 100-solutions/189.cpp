class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> c(nums);
        for (int i = 0; i < nums.size(); i ++) {
            int j = ( i + k ) % nums.size();
            c[j] = nums[i];
        }
    
        nums = c;
    }
};
