class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> m;
        for (string s : strs) {
            vector<int> v(26, 0);
            for (char c: s) v[c - 'a']++;
            m[v].push_back(s);
        }
        vector<vector<string>> res;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            res.push_back(iter->second);
        }
        return res;
    }
};