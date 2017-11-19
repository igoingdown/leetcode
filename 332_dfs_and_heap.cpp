class Solution {
private:
    void dfs(string& start, map<string, priority_queue<string, vector<string>, greater<string>>>& m, list<string>& res) {
        while (!m[start].empty()) {
            string arrival = m[start].top();
            m[start].pop();
            dfs(arrival, m, res);
        }
        res.push_front(start);
    }
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string, priority_queue<string, vector<string>, greater<string>>> m;
        for (auto p : tickets) m[p.first].push(p.second);
        list<string> res;
        string start = "JFK";
        dfs(start, m, res);
        return vector<string>(res.begin(), res.end());
    }
};