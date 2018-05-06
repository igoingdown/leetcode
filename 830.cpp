class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        int b = 0, e = 0, n = S.size();
        while (b < n && e < n) {
            while (e < n && S[e] == S[b]) ++e;
            if (e - b >= 3) res.push_back({b, e - 1});
            b = e;
        }
        return res;
    }
};