class Solution {
public:
    static bool myCompare(pair<string, int> p1, pair<string, int> p2) {
        return (p1.second > p2.second) || (p1.second == p2.second && p1.first < p2.first);
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (string s : words) {
            m[s]++;
        }
        vector<pair<string, int> > v(m.begin(), m.end());
        sort(v.begin(), v.end(), myCompare);
        vector<string> res;
        for (int i = 0; i< k; i++) {
            res.push_back(v[i].first);
        }
        return res;
    }
};