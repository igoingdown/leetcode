class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int minN = INT_MAX, maxN = INT_MIN, l = nums.size(), res = 0;
        if (l == 0) return res;
        for (int n : nums) {
            minN = min(n, minN);
            maxN = max(n, maxN);
        }
        if (maxN == minN) return res;
        int totalBucketsPredicted = nums.size(); //不考虑去重，按一个数一个桶准备桶
        int bucketHight = (maxN - minN) / totalBucketsPredicted + 1; // 根据准备的桶的个数计算bucket_size
        int totalBucketsUsed = (maxN - minN) / bucketHight + 1; // 已知bucket_size，可以去重，理想情况下一数一桶，如果出现空桶，说明有至少两个数落进了一个桶中。这时候，桶间间隔必然大于桶内数据的间隔。一数一桶的情况下，上述结论仍成立（桶内间距为0）。
        vector<vector<int>> buckets(totalBucketsUsed);
        for (int n : nums) {
            int b = (n - minN) / bucketHight;
            if (buckets[b].size() == 0) {
                buckets[b] = vector<int> {n, n};
            } else {
                buckets[b][0] = min(n, buckets[b][0]);
                buckets[b][1] = max(n, buckets[b][1]);
            }
        }
        int pre = -1;
        for (int i = 0; i < buckets.size(); i++) {
            if (buckets[i].size() > 0) {
                if (pre >= 0) {
                    res = max(res, buckets[i][0] - buckets[pre][1]);
                } else {
                    res = buckets[i][1] - buckets[i][0];
                }
                pre = i;
            }
        }
        
        return res;
    }
};
