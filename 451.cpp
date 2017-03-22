class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> alpha2Count;
        for (char c: s) {
            alpha2Count[c]++;
        }
        vector<pair<char, int>> vec(alpha2Count.begin(), alpha2Count.end());
        sort(vec.begin(), vec.end(), myCompare);
        string res;
        for (auto i = vec.begin(); i != vec.end(); i++) {
            for (int k = 0; k < i->second; k++) {
                res.push_back(i->first);
            }
        }
        return res;
    }
    static bool myCompare(pair<char, int>& l, pair<char, int>& r) {
        return l.second > r.second;
    }
};
