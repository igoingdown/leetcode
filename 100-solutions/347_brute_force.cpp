class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for (int n : nums) m[n]++;
        vector<pair<int, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [] (const pair<int, int>& a, const pair<int, int>& b) {return a.second > b.second;});
        vector<int> res;
        for (int i = 0; i < k; i++) res.push_back(v[i].first);
        return res;
    }
};