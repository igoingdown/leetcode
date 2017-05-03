class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i * 2 * k < s.size(); i++) {
            if (i * 2 * k + k > s.size()) {
                reverse(s.begin() + i * 2 *k, s.end());
            } else {
                reverse(s.begin() + i * 2 * k, s.begin() + i * 2 * k + k);
            }
        }
        return s;
    }
};
