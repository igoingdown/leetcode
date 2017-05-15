class Solution {
private:
    map<int, string> m{{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        for (int i = 0; i < digits.size(); i++) {
            int d = digits[i] - '0';
            int original_size = res.size();
            if (original_size == 0) {
                res.resize(m[d].size());
                for (int j = 0; j < m[d].size(); j++) {
                    res[j].push_back(m[d][j]);
                }
                continue;
            } else {
                res.resize(original_size * m[d].size());
            }
            // res.resize((i + 1) * m[d].size());
            for (int j = 0; j < m[d].size(); j++) {
                if (j == 0) {
                    for (int k = 0; k < original_size; k++) {
                        res[k].push_back(m[d][j]);
                    }
                } else {
                    for (int k = 0; k < original_size; k++) {
                        res[j * original_size + k] = res[k].substr(0, res[k].size() - 1) + m[d][j];
                    }
                }
            }
        }
        return res;
    }
};
