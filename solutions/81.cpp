class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int low = 0, high = nums.size() - 1, mid;
            while (low <= high) {
                // 这种写法 high 要更新为 mid - 1，否则会无限循环
                mid = low + ((high - low) >> 1);
                if (nums[mid] == target) {
                    return true;
                }
                if (nums[mid] == nums[high]) { // 无法区分左右半侧是否有序
                    --high; // 更新 high 而不修改 low 原因是已知 nums[mid] != target，high 这个元素没有额外作用
                } else if (nums[mid] < nums[high]) {  // 右半侧有序
                    if (nums[mid]<target && target <= nums[high]) { // target 被右侧区间覆盖
                        low = mid+1;
                    } else {
                        high = mid-1;
                    }
                } else { // 左半侧有序
                    if (nums[low] <= target && target < nums[mid]) { // target 被左侧区间覆盖
                        high = mid - 1;
                    } else {
                        low = mid+1;
                    }
                }
            }
            return false;
        }
    };