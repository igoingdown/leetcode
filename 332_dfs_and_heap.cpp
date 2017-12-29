class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string, priority_queue<string, vector<string>, greater<string>>> m;
        for (auto p: tickets) m[p.first].push(p.second);
        string s = "JFK";
        list<string> res;
        dfs(m, s, res);
        return vector<string> (res.begin(), res.end());
    }
    
    void dfs(map<string, priority_queue<string, vector<string>, greater<string>>>& m, string& start, list<string>& res) {
        while (!m[start].empty()) {
            auto dest = m[start].top();
            m[start].pop();
            dfs(m, dest, res);
        }
        res.push_front(start);
    }
};