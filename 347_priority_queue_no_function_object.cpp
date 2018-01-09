class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for (int n : nums) m[n]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (auto p : m) {
            q.push({p.second, p.first});
            while (q.size() > k) q.pop();
        }
        vector<int> res;
        while (k--) {
            res.push_back(q.top().second);
            q.pop();
        } 
        return res;
    }
};