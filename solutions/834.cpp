class Solution {
private:
    vector<int> ans;
    vector<int> treeNodes; //以节点0位root时，每个节点作为root的子树的节点个数
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

        //通过DFS计算root(节点0)到其他所有节点的距离之和(ans[0])和以节点0为根节点进行DFS时，任意节点i所在的以自身为根节点的子树中节点的个数(treeNodes[i])。
        ans[0] = dfs(0, -1, 0);
        
        //再通过DFS从节点0开始一次计算出所有子节点的ans，复用父节点的ans
        //有公式 ans[child] = ans[parent] + N - 2 * treeNodes[child]
        getAns(0, -1, N);

        return ans;
        
    }
    
    int dfs(int cur, int parent, int dist) {
        int distSum = dist;
        for (int child : graph[cur]) {
            if (child != parent) {
                distSum += dfs(child, cur, dist+1);
                treeNodes[cur] += treeNodes[child];
            }
        }
        treeNodes[cur]++;
        return distSum;
    }
    
    void getAns(int cur, int parent, int N) {
        for (auto child : graph[cur]) {
            if (child != parent) {
                ans[child] = ans[cur] + N - 2 * treeNodes[child];
                getAns(child, cur, N);
            }
        }
    }
};
