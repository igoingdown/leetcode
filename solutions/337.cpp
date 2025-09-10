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
    int rob(TreeNode* root) {
        if (!root) return 0;
        int left = rob(root->left), right = rob(root->right), l = 0, r = 0;
        if (root->left) l = rob(root->left->left) + rob(root->left->right);
        if (root->right) r = rob(root->right->left) + rob(root->right->right);
        return max(left + right, root->val + l + r);
    }
};
