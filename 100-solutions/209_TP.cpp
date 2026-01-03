class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        long long ans = LLONG_MAX, i = 0, j = 0, sum = 0, n = nums.size();
        while (j < n) {
            sum += nums[j];
            if (sum >= s) {
                while(sum - nums[i] >= s) {
                    sum -= nums[i];
                    i++;
                }
                ans = min(ans, j - i + 1);
            }
            j++;
        }
        return ans == LLONG_MAX ? 0: ans;
    }
};