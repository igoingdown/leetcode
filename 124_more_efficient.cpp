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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
    int solve(TreeNode *root, int& res) {
        if (!root) return 0;
        int left = max(0, solve(root->left, res)), right = max(0, solve(root->right, res));
        res = max(res, left + right + root->val);
        return max(left, right) + root->val;
    }
};