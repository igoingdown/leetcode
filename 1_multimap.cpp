class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_multimap<int, int> m;
        for (int i = 0; i < nums.size(); i++) m.insert({target - nums[i], i});
        for (int i = 0; i < nums.size(); i++) {
            auto p = m.equal_range(nums[i]);
            for (auto iter = p.first; iter != p.second; iter++) {
                if (iter->second != i) return {iter->second, i};
            }
        }
        return {0, 0};
    }
};