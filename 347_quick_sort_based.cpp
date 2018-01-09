class Solution {
public:
    map<int, int> m;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (auto n: nums) m[n]++;
        vector<int> s;
        for (auto p : m) s.push_back(p.first);
        int l = s.size(), b = 0, e = l - 1, pos;
        while (1) {
            pos = partition(s, b, e);
            if (pos == l - k) return vector<int>(s.begin() + l - k, s.end());
            else if (pos < l - k) b = pos + 1;
            else e = pos - 1;
        }
    }
    int partition(vector<int>& s, int b, int e) {
        int l = b, r = e, x = s[l];
        while (l < r) {
            while (l < r && m[s[r]] >= m[x]) r--;
            if (l < r) s[l++] = s[r];
            while (l < r && m[s[l]] <= m[x]) l++;
            if (l < r) s[r--] = s[l];
        }
        s[l] = x;
        return l;
    }
};