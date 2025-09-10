class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for (int n : nums) diff ^= n;
        diff &= -diff;
        vector<int> res(2);
        for (int n : nums) {
            if ((n & diff) == 0) res[1] ^= n;
            else res[0] ^= n;
        }
        return res;
    }
};
