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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val == key) {
            if (root->left && root->right) root->val = findAndDelete(root);
            else if (!root->left && !root->right) root = NULL;
            else {
                TreeNode *tmp = root->left ? root->left : root->right;
                root->left = tmp->left; root->val = tmp->val; root->right = tmp->right;
            }
        } else if (root->val < key) root->right = deleteNode(root->right, key);
        else root->left = deleteNode(root->left, key);
        return root;
    }
    
    int findAndDelete(TreeNode *root) {
        TreeNode *parent = root->left, *child = parent->right;
        if (!child) {
            int res = parent->val;
            root->left = parent->left; return res;
        }
        while (child->right) {
            parent = child; child = child->right;
        }
        parent->right = child->left; 
        return child->val;
    }
};