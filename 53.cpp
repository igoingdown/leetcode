class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, sum = 0;
        for (int n : nums) {
            sum += n;
            if (sum < n) sum = n;
            res= max(sum, res);
        }
        return res;
    }
};