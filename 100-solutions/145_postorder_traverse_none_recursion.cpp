/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Node{
    TreeNode* n;
    bool visited;
    Node(TreeNode* t): n(t), visited(false){};
};
class Solution {
private:
    void dfs(TreeNode* root, vector<int>& res) {
        if (!root) return;
        dfs(root->left, res);
        dfs(root->right, res);
        res.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res(0);
        if (!root) return res;
        stack<Node*> s;
        s.push(new Node(root));
        while (s.top()->n->left) s.push(new Node(s.top()->n->left));
        while (!s.empty()) {
            auto cur = s.top();
            if (!cur->n->right || cur->visited) {
                s.pop();
                res.push_back(cur->n->val);
            }
            else {
                cur->visited = true;
                s.push(new Node(cur->n->right));
                while (s.top()->n->left) s.push(new Node(s.top()->n->left));
            }
        }
        return res;
    }
};