class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        backtrack(res, tmp, s, 0);
        return res;
    }
    void backtrack(vector<vector<string>>& res, vector<string>& tmp, string& s, int b) {
        if (b == s.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = b; i < s.size(); i++) {
            if (!isPalindrome(s, b, i)) {
                continue;
            }
            tmp.push_back(s.substr(b, i - b + 1));
            backtrack(res, tmp, s, i + 1);
            tmp.pop_back();
        }
    }
    
    bool isPalindrome(string& s, int b, int e) {
        bool res = true;
        while (b < e) {
            if (! (s[b++] == s[e--])) {
                res = false;
                break;
            }
        }
        return res;
    }
};