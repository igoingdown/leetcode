class Solution {
public:
    bool validUtf8(vector<int>& data) {
        return dfs(data, 0);
    }
    bool dfs(vector<int> &data, int start) {
        if (start >= data.size()) return true;
        return ((data[start] >> 7) == 0 && dfs(data, start + 1)) || (start + 1 < data.size() && (data[start] >> 5) == 0x6 && (data[start + 1] >> 6) == 0x2 && dfs(data, start + 2)) || (start + 2 < data.size() && (data[start] >> 4) == 0xE && (data[start + 1] >> 6) == 0x2 && (data[start + 2] >> 6) == 0x2 && dfs(data, start + 3)) || (start + 3 < data.size() && (data[start] >> 3) == 0x1E && (data[start + 1] >> 6) == 0x2 && (data[start + 2] >> 6) == 0x2 && (data[start + 3] >> 6) == 0x2 && dfs(data, start + 4));
    }
};