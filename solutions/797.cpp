class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path(1, 0);
        vector<bool> visit(graph.size());
        visit[0] = true;
        dfs(graph, 0, path, visit, res);
        return res;
    }
    void dfs(vector<vector<int>> &graph, int start, vector<int> &path, vector<bool> &visit, vector<vector<int>> &res) {
        if ((path.size() > 0 && path.back() + 1 == graph.size())) {
            res.push_back(path); return;
        }
        for (int next : graph[start]) {
            if (!visit[next]) {
                visit[next] = true; path.push_back(next);
                dfs(graph, next, path, visit, res);
                visit[next] = false; path.pop_back();
            }
            
        }
    }
};