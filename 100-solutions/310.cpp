class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<set<int>> g(n, set<int>());
        for (auto edge: edges) {
            g[edge[0]].insert(edge[1]);
            g[edge[1]].insert(edge[0]);
        }
        vector<int> visited(n), res;
        queue<int> cur,next;
        for (int i = 0; i < g.size(); i++)  {
            if (g[i].size() <= 1) {
                cur.push(i);
                visited[i] = 1;
            }
        }
        while (!cur.empty()) {
            res.clear();
            while(!cur.empty()) {
                int node = cur.front(); cur.pop();
                res.push_back(node);
                int neighbor = *(g[node].begin());
                g[node].erase(neighbor);
                g[neighbor].erase(node);
                if (g[neighbor].size() <= 1) {
                    if (visited[neighbor]) {
                        continue;
                    }
                    next.push(neighbor);
                    visited[neighbor] = 1;
                }
            }
            swap(cur, next);
        }
        return res;
    }
};
