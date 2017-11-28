/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    UndirectedGraphNode* dfs(UndirectedGraphNode* node, map<UndirectedGraphNode*, UndirectedGraphNode*>& m) {
        if (m.find(node) == m.end()) {
            m[node] = new UndirectedGraphNode(node->label);
            for (auto neighbor : node->neighbors) m[node]->neighbors.push_back(dfs(neighbor, m));
        }
        return m[node];
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        m[NULL] = NULL;
        return dfs(node, m);
    }
};