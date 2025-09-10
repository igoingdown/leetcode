class Solution {
public:
    bool checkRecord(string s) {
        int a_count = 0, l_count = 0;
        for (auto c: s) {
            if (c == 'A') {
                a_count++;
                l_count = 0;
                if (a_count > 1) {
                    return false;
                }
            } else if (c == 'L') {
                l_count++;
                if (l_count > 2) {
                    return false;
                }
            } else {
                l_count = 0;
            }
        }
        return true;
    }
};
