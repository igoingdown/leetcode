class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        vector<pair<int, int>> intervals;
        for (auto key : words) {
            int pos = 0;
            while (pos < S.size()) {
                int p = S.find(key, pos);
                if (p == string::npos) break;
                else{
                    pos++;
                    intervals.push_back({p, p + key.size()});
                }
            }
        }
        if (intervals.size() == 0) return S;
        sort(intervals.begin(), intervals.end(), myCompare);
        vector<pair<int, int>> res(1, intervals[0]);
        for (auto p : intervals) {
            if (p.first <= res.back().second) res.back().second = max(p.second, res.back().second);
            else res.push_back(p);
        }
        string s1 = "<b>", s2 = "</b>", s;
        int last = 0;
        for (auto p : res) {
            s += S.substr(last, p.first - last);
            s += s1;
            s += S.substr(p.first, p.second - p.first);
            s += s2;
            last = p.second;
        }
        s += S.substr(last, S.size() - last);
        return s;
    }
    
    static bool myCompare(pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first;
    }
};