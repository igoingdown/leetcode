class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int c0 = 0, c1 = 0;
            for (int n : nums) {
                n >> i & 1 ? c1++ : c0++;
            }
            res += c0 * c1;
        }
        return res;
    }
};