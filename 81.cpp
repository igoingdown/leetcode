class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = nums.size(), low = 0, high = s - 1, mid;
        if (s == 0) return false;
        while (low < high) {
            mid = low + ((high - low) >> 1);
            if (nums[mid] == target) return true;
            if (nums[mid] > nums[low]) {
                if (nums[low] <= target && nums[mid] > target) high = mid - 1;
                else low = mid + 1;
            } else if (nums[mid] < nums[low]) {
                if (nums[mid] < target && nums[high] >= target) low = mid + 1;
                else high = mid - 1;
            } else low++;
        }
        return nums[low] == target;
    }
};