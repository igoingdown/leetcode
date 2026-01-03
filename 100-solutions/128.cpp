class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = 0;
        for (int num: nums) {
            if (m.find(num) == m.end()) {
                int left = m.find(num - 1) == m.end() ? 0 : m[num - 1];
                int right = m.find(num + 1) == m.end() ? 0 : m[num + 1];
                int sum = left + right + 1;
                m[num] = sum;
                res = max(sum, res);
                m[num - left] = sum;
                m[num + right] = sum;
            }
        }
        return res;
    }
};