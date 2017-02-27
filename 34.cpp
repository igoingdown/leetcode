class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return vector<int> (2, -1);
        }
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if (nums[low] != target) {
            return vector<int> (2, -1);
        }
        
        vector<int> res(2, low);
        while (nums[low] == target && low < nums.size()) {
            low++;
        }
        res[1] = low - 1;
        return res;
    }
};
