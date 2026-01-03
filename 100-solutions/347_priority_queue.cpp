class Comparison{
public:
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for (int n : nums) m[n]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparison> q;
        for (auto p : m) q.push(p);
        vector<int> res;
        while (k--) {
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    }
};