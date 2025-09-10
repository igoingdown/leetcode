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
        maxPathSum(root, res);
        return res;
    }
    void maxPathSum(TreeNode *root, int &res) {
        if (!root) return;
        int l = root->val, r = l, s = l;
        if (root->left) {
            int t = INT_MIN;
            maxSidePathSum(root->left, 0, t);
            s += t; l += t;
        }
        if (root->right) {
            int t = INT_MIN;
            maxSidePathSum(root->right, 0, t);
            s += t; r += t;
        }
        res = max(res, max(root->val, max(s, max(l, r))));
        maxPathSum(root->left, res);
        maxPathSum(root->right, res);
    }
    void maxSidePathSum(TreeNode *root, int sum, int& res) {
        sum += root->val; res = max(res, sum);
        if (root->left) maxSidePathSum(root->left, sum, res);
        if (root->right) maxSidePathSum(root->right, sum, res);
    }
};