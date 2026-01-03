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
    void dfs(TreeNode* root, int p) {
        if (!root) return;
        if (!root->left && !root->right) root->val += p;
        if (root->right) {
            root->right->val += p;
            dfs(root->right, p);
            root->val += root->right->val;
        } 
        if (root->left) {
            dfs(root->left, root->val);
        }
    } 
public:
    TreeNode* convertBST(TreeNode* root) {
        dfs(root, 0);
        return root;
    }
};