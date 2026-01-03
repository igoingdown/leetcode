class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.size() < 2) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int b = 0, e = 1, count = 0;
        while (b < e && e < nums.size()) {
            if (nums[e] - nums[b] == k) {
                count++;
                do {
                    b++;
                    e++;
                } while (nums[e] == nums[e - 1] && nums[b] == nums[b - 1]);
            } else if (nums[e] - nums[b] < k) {
                e++;
            } else {
                b++;
            }
            if (b == e) {
                e++;
            }
        }
        return count;
    }
};
