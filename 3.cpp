class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(256, -1);
        int start = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (v[s[i]] >= start) start = v[s[i]] + 1;
            v[s[i]] = i;
            res = max(res, i - start + 1);
        }
        return res;
    }
};