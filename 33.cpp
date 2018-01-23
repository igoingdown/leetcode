class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = nums.size(), low, high, mid;
        if (s == 0) return -1;
        low = 0; high = s - 1;
        while (low < high) {
            mid = low + ((high - low) >> 1);
            if (nums[mid] == target) return mid;
            if (nums[low] <= nums[mid]) {     // 这里要注意是小于等于，只有这样才可以确定相反情况下mid处于较小的后半段
                if (nums[mid] > target && nums[low] <= target) high = mid - 1;
                else low = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }
        return nums[low] == target ? low : -1;
    }
};