class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) {
            return false;
        }
        long long target = sum >> 1;
        bitset<10001> bits(1);
        for (auto n: nums) {
            bits |= (bits << n);
        }
        return bits[target];
    }
};