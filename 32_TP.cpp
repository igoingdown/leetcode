class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, left = 0, right = 0, n = s.size();
        if (n == 0) return 0;
        for (char c : s) {
            if (c == '(') left++;
            else right++;
            if (left < right) left = right = 0;
            else if (left == right) res = max(res, (right) << 1);
        }
        left = right = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') left++;
            else right++;
            if (left > right) left = right = 0;
            else if (left == right) res = max(res, (right) << 1);
        }
        return res;
    }
};
