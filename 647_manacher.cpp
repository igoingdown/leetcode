class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), m = (n << 1) + 1;
        string buffer(m, '#');
        for (int i = 0; i < n; i++) buffer[(i << 1) + 1] = s[i];
        int total = 0;
        vector<int> max_len(m);
        int ID = 0, max_pos = 0;
        for (int i = 0; i < m; i++) {
            max_len[i] = max_pos > i ? min(max_pos - i, max_len[(ID << 1) - i]) : 1;
            while (i + max_len[i] < m && i - max_len[i] >= 0 && buffer[i + max_len[i]] == buffer[i - max_len[i]]) max_len[i]++;
            if (i + max_len[i] > max_pos) {
                max_pos = i + max_len[i];
                ID = i;
            }
            total += buffer[i] == '#' ? (max_len[i] >> 1): ((max_len[i] + 1) >> 1);
        }
        return total;
    }
};