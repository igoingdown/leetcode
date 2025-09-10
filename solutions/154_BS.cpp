class Solution {
    public:
        int findMin(vector<int>& nums) {
            int low = 0, high = nums.size() - 1;
            while (low < high) {
                if (nums[low] < nums[high]) {
                    high = low + (high - low) / 2;
                } else {
                    ++low;
                }
            }
            return nums[low];
        }
    }