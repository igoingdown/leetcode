class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0, res = 0, tmp = 0;
        set<int> s;
        for (int i = 31; i >= 0; i--) {
            mask |= (1 << i);
            for (int n : nums) s.insert(n & mask);
            tmp = res | (1 << i);
            for (auto i = s.begin(); i != s.end(); i++) {
                if (s.find((*i) ^ tmp) != s.end()) {
                    res = tmp;
                    break;
                }
            }
            s.clear();
        }
        return res;
    }
};