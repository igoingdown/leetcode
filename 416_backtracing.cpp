class Solution {
private:
    bool backtrack(vector<int>& nums, int s, int t) {
        if (t <= 0) {
            return t==0;
        }
        for (int i = s; i < nums.size(); i++) {
            if (backtrack(nums, i+1, t - nums[i])) {
                return true;
            }
        }
        return false;
    }
public:
    bool canPartition(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        return (!(sum % 2)) && backtrack(nums, 0, sum >> 1);
    }
};