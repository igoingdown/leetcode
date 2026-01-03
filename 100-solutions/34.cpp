class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int n = nums.size();
        if (n == 0) return res;
        int low = 0, high = n - 1, mid;
        while (low < high) {
            mid = low + ((high - low) >> 1);
            if (nums[mid] < target) low = mid + 1;
            else high = mid;
        }
        res[0] = nums[low] == target ? low : -1; 
        low = 0, high = n - 1;
        while (low < high) {
            mid = low + ((high - low + 1) >> 1);
            if (nums[mid] > target) high = mid - 1;
            else low = mid;
        }
        res[1] = nums[low] == target ? low : -1;
        return res;
    }
};