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
    void dfs(TreeNode* t, int s, int& res) {
        if (s == t->val) res += 1;
        if (t->left) dfs(t->left, s - t->val, res);
        if (t->right) dfs(t->right, s - t->val, res);
    }
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        if (!root) return res;
        dfs(root, sum, res);
        if (root->left) res += pathSum(root->left, sum);
        if (root->right) res += pathSum(root->right, sum);
        return res;
    }
};