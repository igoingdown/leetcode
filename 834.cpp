class Solution {
private:
    int n;
    vector<vector<int>> es;
    vector<int> ss;
    vector<int> ans;
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n = N;
        es.resize(N, vector<int>(0));
        ss.resize(N);
        ans.resize(N);
        for (const auto &edge : edges) {
            es[edge[0]].push_back(edge[1]);
            es[edge[1]].push_back(edge[0]);
        }
        g(0, -1, f(0, -1, 0));
        return ans;
    }
    
    int f(int u, int p, int d) {
        int ds = d;
        ss[u] = 1;
        for (int v : es[u]) {
            if (v != p) {
                ds += f(v, u, d + 1);
                ss[u] += ss[v];
            }
        }
        return ds;
    }
    
    void g(int u, int p, int tot) {
        ans[u] = tot;
        for (int v : es[u]) {
            if (v != p) {
                g(v, u, tot - ss[v] * 2 + n);
            }
        }
    }
};