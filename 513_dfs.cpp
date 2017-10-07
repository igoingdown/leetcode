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
private:
    void dfs(TreeNode* root, int& max_level, int& res, int d) {
        if (!root) {
            return;
        }
        dfs(root->left, max_level, res, d+1);
        dfs(root->right, max_level, res, d+1);
        if (d > max_level) {
            max_level = d;
            res = root->val;
        }
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        int res = root->val;
        int max_level = 0;
        dfs(root, max_level, res, 0);
        return res;
    }
};