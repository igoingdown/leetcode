class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j = -1, res = 0;
        vector<int> v(256, -1);
        for (int i = 0; i < s.size(); i++) {
            if (v[s[i]] >= 0) {
                j = max(j, v[s[i]]);
            }
            v[s[i]] = i;
            res = max(res, i - j);
        }
        return res;
    }
};