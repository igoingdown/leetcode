class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        for (int i = 0; i < s.size();) {
            while (s[i] == ' ' && i < s.size()) {
                i++;
            }
            if (! (i < s.size())) {
                return res;
            }
            while (s[i] != ' ' && i < s.size()) {
                i++;
            }
            res++;
        }
        return res;
    }
};
