class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s1("qwertyuiop");
        string s2("asdfghjkl");
        string s3("zxcvbnm");
        unordered_set<char> m1(s1.begin(), s1.end());
        unordered_set<char> m2(s2.begin(), s2.end());
        unordered_set<char> m3(s3.begin(), s3.end());
        vector<string> res;
        for (auto w: words) {
            if(w.size() == 0) {
                res.push_back(w);
            }
            unordered_set<char> temp;
            char ch;
            if (w[0] <= 'Z' && w[0] >= 'A') {
                ch = w[0] + 32;
            } else {
                ch = w[0];
            }
            if (m1.find(ch) != m1.end()) {
                temp = m1;
            } else if (m2.find(ch) != m2.end()) {
                temp = m2;
            } else if (m3.find(ch) != m3.end()) {
                temp = m3;
            } else {
                continue;
            }
            bool flag = true;
            for (auto c: w) {
                if (c <= 'Z' && c >= 'A') {
                    ch = c + 32;
                } else {
                    ch = c;
                }
                if (temp.find(ch) == temp.end()) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.push_back(w);
            }
        }
        return res;
    }
};
