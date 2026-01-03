class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;
        int res = 0;
        vector<int> v(n + 1, 0);
        m[0] = 0;
        for (int i = 0; i < n; i++) {
            v[i + 1] = v[i] + (nums[i] == 0 ? -1 : 1);
            auto iter = m.find(v[i + 1]);
            if (iter != m.end()) {
                res = max(res, i + 1 - iter->second);
            } else m[v[i + 1]] = i + 1;
        }
        return res;
    }
};