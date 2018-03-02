class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) m[target - nums[i]] = i;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end() && i != m[nums[i]]) return {i, m[nums[i]]};
        }
        return {0, 0};
    }
};