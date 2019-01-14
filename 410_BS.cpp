class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long low = 0, high = 0, mid;
        for (int& num : nums) {
            low = max(low, long(num));
            high += num;
        }
        while (low < high) {
            mid = low + ((high - low) >> 1);
            if (valid(nums, mid, m)) low = mid + 1;
            else high = mid;
        }
        return low;
    }
    
    bool valid(vector<int>& nums, long long t, int m) {
        int count = 1;
        long sum = 0;
        for (int& num : nums) {
            sum += num;
            if (sum > t) {
                count++;
                sum = num;
            }
            if (count > m) return true;
        }
        return false;
    }
};