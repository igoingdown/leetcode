class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector< set<int> > graph(n, set<int>());
        for (pair<int, int> p : edges) {
            graph[p.first].insert(p.second);
            graph[p.second].insert(p.first);
        }
        queue<int> leaves;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() <= 1) leaves.push(i);
        }
        while (n > 2) {
            n -= leaves.size();
            queue<int> new_leaves;
            while (!leaves.empty()) {
                int cur = leaves.front();
                leaves.pop();
                int neighbor = *(graph[cur].begin());
                graph[cur].erase(neighbor);
                graph[neighbor].erase(cur);
                if (graph[neighbor].size() == 1) new_leaves.push(neighbor);
            }
            leaves = new_leaves;
        }
        vector<int> res;
        while (!leaves.empty()) {
            res.push_back(leaves.front());
            leaves.pop();
        }
        return res;
    }
};