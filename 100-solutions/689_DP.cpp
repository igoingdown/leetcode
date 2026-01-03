class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), max_sum = 0;
        vector<int> res(3), posLeft(n), posRight(n, n - k), sum(1);
        for (int i : nums) sum.push_back(sum.back() + i);
        for (int i = k, tot = sum[k] - sum[0]; i < n; i++) {
            if (sum[i + 1] - sum[i - k + 1] > tot) {
                tot = sum[i + 1] - sum[i - k + 1];
                posLeft[i] = i - k + 1;
            } else posLeft[i] = posLeft[i - 1];
        }
        for (int i = n - k - 1, tot = sum[n] - sum[n - k]; i >= 0; i--) {
            if (sum[i + k] - sum[i] >= tot) {
                tot = sum[i + k] - sum[i];
                posRight[i] = i;
            } else posRight[i] = posRight[i + 1]; 
        }
        for (int i = k; i <= n - 2 * k; i++) {
            int left = posLeft[i - 1], right = posRight[i + k];
            int tmp = sum[i + k] - sum[i] + sum[right + k] - sum[right] + sum[left + k] - sum[left];
            if (tmp > max_sum) {
                max_sum = tmp;
                res[0] = left; res[1] = i; res[2] = right;
            }
        }
        return res;
    }
};