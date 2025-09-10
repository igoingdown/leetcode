class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        int res = 0, sum = 0;
        m[0]++;
        for (int n : nums) {
            sum += n;
            res += m[sum - k];
            m[sum]++;
        }
        return res;
    }
};