class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int n = fronts.size();
        if (n == 0) return 0;
        set<int> s;
        vector<bool> res(2000 + 1, false);
        for (int i = 0; i < n; i++) {
            s.insert(fronts[i]); s.insert(backs[i]);
            if (fronts[i] == backs[i]) res[fronts[i]] = true;
        }
        for (const int &i : s) {
            if (!res[i]) return i;
        }
        return 0;
    }
};