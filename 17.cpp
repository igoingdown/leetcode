class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return vector<string> ();
        unordered_map<int, string> m({{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}});
        vector<string> res(1, "");
        string tmp;
        for (char c : digits) {
            int s = res.size();
            for (int i = 0; i < m[c - '0'].size() - 1; i++) {
                for (int j = 0; j < s; j++) {
                    tmp = res[j];
                    tmp.push_back(m[c - '0'][i + 1]);
                    res.push_back(tmp);
                }
            }
            for (int j = 0; j < s; j++) {
                res[j].push_back(m[c - '0'][0]);
            }
        }
        return res;
    }
};