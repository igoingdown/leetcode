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
    int sumNumbers(TreeNode* root) {
        int res = 0, num = 0;
        dfs(root, res, num);
        return res;
    }
    void dfs(TreeNode* root, int& res, int& num) {
        if (!root) return;
        num = num * 10 + root->val;
        if (!root->left && !root->right) res += num;
        if (root->left) dfs(root->left, res, num);
        if (root->right) dfs(root->right, res, num);
        num /= 10;
    }
};