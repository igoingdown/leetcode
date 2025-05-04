class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            if (nums.size() == 0) {
                return vector<int> {-1, -1};
            }
            int low = 0, high = nums.size() - 1, mid;
            while (low < high) {
                mid = low + (high - low) / 2;
                if (nums[mid] < target) {
                    low = mid+1;
                } else {
                    high = mid;
                }
            }
            if (nums[low] != target) {
                return vector<int> {-1, -1};
            }
            vector<int> res(2, low);
            low = 0; high = nums.size() - 1;
            while (low < high) {
                mid = low + (high - low) / 2;
                if (nums[mid] > target) {
                    high = mid-1;
                } else if (nums[mid] == target) {
                    if (nums[mid+1] == target) {
                        low = mid+1;
                    } else {
                        high = mid;
                    }
    
                } else {
                    low = mid + 1;
                }
            }
            res[1] = low;
            return res;
        }
    };