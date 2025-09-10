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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> s;
        for (; root; s.push(root), root = root->left);
        while (!s.empty()) {
            auto cur = s.top();
            s.pop();
            res.push_back(cur->val);
            cur = cur->right;
            for (; cur; s.push(cur), cur = cur->left);
        }
        return res;
    }
};