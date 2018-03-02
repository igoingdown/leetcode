class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> copy(nums);
        sort(copy.begin(), copy.end());
        int l = 0, r = nums.size() - 1, sum;
        while (l < r) {
            sum = copy[l] + copy[r];
            if (sum == target) break;
            else if (sum > target) r--;
            else l++;
        }
        vector<int> res(2, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == copy[l]) {
                res[0] = i; break;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == copy[r]) {
                if (copy[l] != copy[r] || (copy[l] == copy[r] && i != res[0])) {
                    res[1] = i; break;
                }
            }
        }
        return res;
    }
};