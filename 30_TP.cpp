class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int ws = words.size(), ss = s.size(), l;
        if (ws == 0) return res;
        l = words[0].size();
        map<string, int> m;
        for (auto word : words) m[word]++;
        for (int i = 0; i <= ss - ws * l; i++) {
            map<string, int> copy(m);
            for (int j = 0; j < ws; j++) {
                string str = s.substr(i + l * j, l);
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