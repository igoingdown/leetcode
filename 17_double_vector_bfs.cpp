class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res, next; 
        if (digits.size() == 0) return res;
        map<int, string> m({{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}});
        res.push_back("");
        for (char d : digits) {
            for (char c : m[d - '0']) {
                for (string str: res) {
                    str.push_back(c);
                    next.push_back(str);
                }
            }
            swap(res, next);
            next.resize(0);
        }
        return res;
    }
};