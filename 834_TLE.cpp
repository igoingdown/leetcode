class Solution {
private:
    vector<int> ans;
    vector<vector<int>> graph;
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        ans.resize(N);
        graph.resize(N, vector<int>());
        treeNodes.resize(N);
        // 构建graph
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        //对于每个节点i，将其视为树的根节点root，通过DFS计算root到其他所有节点的距离之和(ans[i])
		//这样做会超时，因为上述DFS过程只需对一个节点做即可，后面可以复用之前得到的答案ans
        for (int i = 0; i < N; i++) {
            ans[i] = dfs(i, -1, 0);
        }
        return ans;
    }
    
    int dfs(int cur, int parent, int dist) {
        int distSum = dist;
        for (int child : graph[cur]) {
            if (child != parent) {
                distSum += dfs(child, cur, dist+1);
            }
        }
        return distSum;
    }
};
