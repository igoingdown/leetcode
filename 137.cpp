class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int  i = 0; i < 32; i++) {
            int bit_sum = 0;
            for (int n : nums) {
                bit_sum += (n >> i & 1);
            }
            res |= ((bit_sum % 3) << i);
        }
        return res;
    }
};