class Solution {
private:
    bool allZero(vector<int>& v) {
        for (auto i : v) {
            if (i) {
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> status(26, 0);
        for (auto c: s1) {
            status[c - 'a']++;
        }
        for (int i = 0; i < s1.size(); i++) {
            status[s2[i] - 'a']--;
        }
        if (allZero(status)) {
            return true;
        }
        for (int i = s1.size(); i < s2.size(); i++) {
            status[s2[i] - 'a']--;
            status[s2[i - s1.size()] - 'a']++;
            if (allZero(status)) {
                return true;
            }
        }
        return false;
    }
};
