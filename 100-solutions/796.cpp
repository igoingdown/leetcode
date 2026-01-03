class Solution {
public:
    bool rotateString(string A, string B) {
        vector<int> a_map(256), b_map(256);
        for (char c : A) a_map[c]++;
        for (char c : B) b_map[c]++;
        if (a_map != b_map) return false;
        for (int i = 0; i < A.size(); i++) {
            string tmp(A);
            reverse(tmp.begin(), tmp.begin() + i + 1);
            reverse(tmp.begin() + i + 1, tmp.end());
            reverse(tmp.begin(), tmp.end());
            if (tmp == B) return true;
        }
        return false;
    }
};