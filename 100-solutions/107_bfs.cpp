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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q, next;
        q.push(root);
        while (!q.empty()) {
            vector<int> layer;
            while (!q.empty()) {
                TreeNode* cur = q.front();
                q.pop();
                layer.push_back(cur->val);
                if (cur->left) next.push(cur->left);
                if (cur->right) next.push(cur->right);
            }
            res.push_back(layer);
            swap(q, next);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};