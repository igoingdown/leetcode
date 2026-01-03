class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int n = nums.size();
        auto iter = lower_bound(nums.begin(), nums.end(), target);
        if (iter != nums.end() && (*iter == target)) res[0] = iter - nums.begin();
        iter = upper_bound(nums.begin(), nums.end(), target);
        if (iter != nums.begin() && (*(iter - 1) == target)) res[1] = iter - nums.begin() - 1;
        return res;
    }
};
