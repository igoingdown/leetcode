class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, long long> m;
        int s = nums.size();
        if (t < 0 || s < 2 || k < 1) return false;
        for (int i = 0; i < s; i++) {
            long long a = nums[i], tmp = t;
            a -= INT_MAX;
            long long bucket = a / (tmp + 1);
            if (m.find(bucket) != m.end() || 
                (m.find(bucket - 1) != m.end() && a - m[bucket - 1] <= t) ||
                (m.find(bucket + 1) != m.end() && m[bucket + 1] - a <= t)) return true;
            if (m.size() >= k) {
                long long last_num = nums[i - k];
                m.erase((last_num - INT_MAX) / (tmp + 1));
            }
            m[bucket] = a;
        }
        return false;
    }
};