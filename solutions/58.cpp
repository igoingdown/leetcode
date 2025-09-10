class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = s.size(), res = 0;
        while (l > 0 && s[l - 1] == ' ') l--;
        for (; l - res > 0 && s[l - res - 1] != ' '; res++);
        return res;
    }
};