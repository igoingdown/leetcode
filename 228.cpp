class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int b = 0, e = 0;
        while (e < nums.size()) {
            while (e < nums.size() && (e == b || nums[e] == nums[e - 1] + 1)) e++;
            if (e - b > 1) ans.push_back(to_string(nums[b]) + "->" + to_string(nums[e - 1]));
            else ans.push_back(to_string(nums[b]));
            b = e;
        }
        return ans;
    }
};