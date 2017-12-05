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
    int s = 0;
    void dfs(TreeNode* root) {
        if (!root) return;
        if (root->right) {
            dfs(root->right);
        } 
        root->val = (s += root->val);
        if (root->left) {
            dfs(root->left);
        }
    } 
public:
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};