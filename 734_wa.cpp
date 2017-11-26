class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        map<string, set<string>> m;
        for (auto p : pairs) {
            if (m.find(p.first) == m.end()) m[p.first].insert(p.second);
            if (m.find(p.second) == m.end()) m[p.second].insert(p.first);
        }
        set<string> s1(words1.begin(), words1.end()), s2(words2.begin(), words2.end());
        vector<string> tmp(1000);
        for (string s: words1) {
            if (m.find(s) == m.end()) return false;
            else {
                tmp.resize(0);
                auto iter = set_intersection(m[s].begin(), m[s].end(), s2.begin(), s2.end(), tmp.begin());
                if (iter == tmp.begin()) return false;
            }
        }
        for (string s: words2) {
            if (m.find(s) == m.end()) return false;
            else {
                tmp.resize(0);
                auto iter = set_intersection(m[s].begin(), m[s].end(), s1.begin(), s1.end(), tmp.begin());
                tmp.resize(iter - tmp.begin())
                if (tmp.size() == 0) return false;
            }
        }
        return true;
    }
};