class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long low = 0, high = 0, mid = 0;
        for (int& n : nums) {
            long long num = n;
            low = max(low, num);
            high += n;
        }
        while (low <= high) {
            mid = low + ((high - low) >> 1);
            if (valid(nums, mid, m)) low = mid +1;
            else high = mid - 1;
        }
        return low;
    }
    
    bool valid(vector<int>& nums, int t, int m) {
        int count = 1;
        long long sum = 0;
        for (int& n : nums) {
            sum += n;
            if (sum > t) {
                sum = n;
                count += 1;
            }
            if (count > m) return true;
        }
        return false;
    }
};
