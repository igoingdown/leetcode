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
    void recoverTree(TreeNode* root) {
        TreeNode *first = NULL, *second = NULL, *pre = new TreeNode(INT_MIN);
        traverse(root, &first, &second, &pre);
        swap(first->val, second->val);
    }
    void traverse(TreeNode *root, TreeNode **first, TreeNode **second, TreeNode **pre) {
        if (!root) return;
        traverse(root->left, first, second, pre);
        if (!(*first) && (*pre)->val >= root->val) *first = *pre;
        if ((*first) && (*pre)->val >= root->val) *second = root;
        *pre = root;
        traverse(root->right, first, second, pre);
    }
};