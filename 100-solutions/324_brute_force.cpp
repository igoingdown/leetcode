class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        int n = nums.size();
        for (int i = n - 1, j = 0, k = i / 2 + 1; i >= 0; i--) {
            nums[i] = tmp[((i & 1) ? k++ : j++)];
        }
    }
};