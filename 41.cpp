class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> v(nums.size() + 1, 0);
        for (int n : nums) {
            if (n > 0 && n <= nums.size()) v[n - 1] = 1;
        }
        int i = 0;
        while (i <= nums.size() && v[i] != 0) i++;
        return i + 1;
    }
};