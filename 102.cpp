/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q, next;
        q.push(root);
        vector<int> layer;
        while (!q.empty()) {
            while (!q.empty()) {
                auto cur = q.front();
                layer.push_back(cur->val);
                q.pop();
                if (cur->left) next.push(cur->left);
                if (cur->right) next.push(cur->right);
            }
            swap(q, next);
            res.push_back(layer);
            layer.resize(0);
        }
        return res;
    }
};