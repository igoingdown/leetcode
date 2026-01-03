class Solution {
public:
    // 基于回溯的方法会超时！这个题不适合回溯！也可能是我写的回溯算法优化不够好！
    int minCut_Backtracing(string s) {
        if (s.size() < 2) {
            return 0;
        }
        int res = -1;
        vector<string> tmp;
        backtrack(res, tmp, s, 0);
        return res;
    }
    bool isPalindrome(const string& s, int b, int e) {
        while (b < e) {
            if (s[b++] != s[e--]) {
                return false;
            }
        }
        return true;
    }
    void backtrack(int& res, vector<string>& tmp, const string& s, int b) {
        if (b == s.size()) {
            if (res < 0) {
                res = tmp.size() - 1;
            } else {
                res = min(res, (int)(tmp.size()) - 1);
            }
            
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
};