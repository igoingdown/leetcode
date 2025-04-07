class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0, mask = 0;
        for (int i = 30; i >= 0; i--) {
            mask |= (1 << i);
            int tmp = res | (1 << i);
            unordered_set<int> prefixs;
            for (auto n : nums) {
                prefixs.insert(n & mask);
            }
            for (auto p : prefixs) {
                if (prefixs.find(p ^ tmp) != prefixs.end()) {
                    res = tmp;
                    break;
                }
            }
        }
        return res;
    }
};
