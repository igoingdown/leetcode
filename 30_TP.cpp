class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> m, copy;
        for (string word : words) m[word]++;
        vector<int> res;
        if (words.size() == 0) return res;
        int l = words[0].size(), ss = s.size(), ws = words.size();
        for (int i = 0; i <= ss - l * ws; i++) {
            unordered_map<string, int> copy(m);
            for (int j = 0; j < words.size(); j++) {
                auto str = s.substr(i + l * j, l);
                if (copy.find(str) != copy.end()) {
                    if (copy[str] == 1) copy.erase(str);
                    else copy[str]--;
                    if (copy.empty()) {
                        res.push_back(i); break;
                    }
                } else break;
            }
        }
        return res;
    }
};