class Solution {
private:
    vector<int> _nums;
public:
    Solution(vector<int> nums) {
        _nums = nums;
    }
    
    int pick(int target) {
        int n = 0, res;
        for (int i = 0; i < _nums.size(); i++) {
            if (_nums[i] != target) continue;
            n++;
            if (rand() % n == 0) res = i;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */