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
    TreeNode *first, *second, *pre;
public:
    void recoverTree(TreeNode* root) {
        first = NULL, second = NULL, pre = new TreeNode(INT_MIN);
        traverse(root);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
    void traverse(TreeNode *root) {
        if (!root) return;
        traverse(root->left);
        if (!first && pre->val >= root->val) first = pre;
        if (first && pre->val >= root->val) second = root;
        pre = root;
        traverse(root->right);
    }
};