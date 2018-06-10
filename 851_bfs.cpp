class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        queue<int> q, next;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) ans[i] = i;
        map<int, set<int>> m;
        set<int> s;
        for (const vector<int> & v : richer) {
            m[v[1]].insert(v[0]);
            s.insert(v[1]);
        }
        bool visit[n];
        memset(visit, false, sizeof visit);
        for (int i = 0; i < n; i++) {
            if (s.find(i) == s.end()) {
                q.push(i);
                visit[i] = true;
            }
        }
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            m.erase(cur);
            for (auto iter = m.begin(); iter != m.end(); iter++) {
                if (iter->second.find(cur) != iter->second.end()) {
                    ans[iter->first] = quiet[iter->first] >= quiet[cur] ? ans[cur] : ans[iter->first];
                    quiet[iter->first] = min(quiet[iter->first], quiet[cur]);
                    iter->second.erase(cur);
                }
                if (iter->second.empty() && !visit[iter->first]) {
                    q.push(iter->first);
                    visit[iter->first] = true;
                }
            }
        }
        return ans;
    }
};