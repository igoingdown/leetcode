class Solution {
public:
    int hIndex(vector<int>& citations) {
        int c_size = citations.size();
        vector<int> count(c_size + 1, 0);
        for (int i = 0; i < c_size; i++) {
            if (citations[i] >= c_size) {
                count[c_size]++;
            } else {
                count[citations[i]]++;
            }
        }
        int res = 0;
        for (int i = c_size; i >= 0; i--) {
            res += count[i];
            if (res >= i) {
                return i;
            }
        }
        return 0;
    }
};
