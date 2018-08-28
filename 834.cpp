class Solution {
private:
    int n;
    vector<vector<int>> graph;
    vector<int> nodes;
    vector<int> ans;
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n = N;
        graph.resize(N, vector<int>(0));
        nodes.resize(N);
        ans.resize(N);
        for (const auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int tot = f(0, -1, 0);
        g(0, -1, tot);
        return ans;
    }
    
    int f(int cur, int parent, int d) {
        int ds = d;
        nodes[cur] = 1;
        for (int child : graph[cur]) {
            if (child != parent) {
                ds += f(child, cur, d + 1);
                nodes[cur] += nodes[child];
            }
        }
        return ds;
    }
    
    void g(int cur, int parent, int tot) {
        ans[cur] = tot;
        for (int child : graph[cur]) {
            if (child != parent) {
                g(child, cur, tot - nodes[child] * 2 + n);
            }
        }
    }
};