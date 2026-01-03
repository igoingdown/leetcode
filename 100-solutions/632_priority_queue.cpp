class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size(), minr = INT_MAX;
        vector<int> pos(k);
        map<int, vector<int>> m;
        vector<int> res(2);
        for (int i = 0; i < k; i++) m[nums[i][pos[i]]].push_back(i);
        while (true) {
            auto iter1 = m.begin(), iter2 = prev(m.end());
            if (iter2->first - iter1->first < minr) {
                minr = iter2->first - iter1->first;
                res[0] = iter1->first; res[1] = iter2->first;
            }
            vector<int> v = iter1->second;
            m.erase(iter1);
            for (int i : v) {
                pos[i]++;
                if (pos[i] >= nums[i].size()) return res;
                m[nums[i][pos[i]]].push_back(i);
            }
        }
        return res;
    }
};