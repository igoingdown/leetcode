class Solution {
public:
    char findTheDifference(string s, string t) {
        char res;
        vector<int> s_vec(26, 0);
        vector<int> t_vec(26, 0);
        for (auto c: s) {
            s_vec[c - 'a'] ++;
        }
        for (auto c: t) {
            t_vec[c - 'a'] ++;
        }
        for (int i = 0; i < 26; i++) {
            if (s_vec[i] != t_vec[i]) {
                res = i + 'a';
                break;
            }
        }
        return res;
    }
};