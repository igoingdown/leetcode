class Solution {
private:
    int root(vector<int>& parent, int k) {
        if (parent[k] != k) {
            parent[k] = root(parent, parent[k]);
        }
        return parent[k];
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(2001, 0);
        for (int i = 0; i < 2001; i++) {
            parent[i] = i;
        }
        for (auto edge : edges) {
            int pa = root(parent, edge[0]);
            int pb = root(parent, edge[1]);
            if (pa == pb) {
                return edge;
            }
            parent[pb] = pa;
        }
        return vector<int> (0, 0);
    }
};