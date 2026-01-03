class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), max_len = 0, res = 0;
        vector<int> len(n, 1); // length of LIS ending with nums[i].
        vector<int> cnt(n, 1); // count of LIS ending with nums[i].
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) { // increasing pair
                    if (len[j]+ 1 > len[i]) { // a longer LIS found, reset the count to the new one
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (len[j] + 1 == len[i]) { //another same length, add number of solutions to it
                        cnt[i] += cnt[j];
                    }
                }
            }
            max_len = max(max_len, len[i]);
        }
        for (int i = 0; i < n; i++) {
            res += (len[i] == max_len ? cnt[i] : 0);
        }
        return res;
    }
};