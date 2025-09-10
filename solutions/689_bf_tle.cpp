class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), tot = 0;
        vector<int> res(3);
        for (int i = 0; i <= n - k * 3; i++) {
            for (int j = i + k; j <= n - k * 2; j++) {
                for (int m = j + k; m <= n - k; m++) {
                    int sum = 0;
                    for (int l = 0; l < k; l++) sum += nums[i + l] + nums[j + l] + nums[m + l];
                    if (sum > tot) {
                        tot = sum;
                        res[0] = i; res[1] = j; res[2] = m;
                    }
                }
            }
        }
        return res;
    }
};