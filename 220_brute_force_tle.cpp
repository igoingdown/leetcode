class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int s = nums.size();
        if (s < 2) return false;
        long long a, b;
        for (int i = 0; i < s; i++) {
            for (int j = i + 1; j < s && j <= i + k; j++) {
                a = nums[i], b = nums[j];
                if (abs(a - b) <= t) return true;
            }
        }
        return false;
    }
};