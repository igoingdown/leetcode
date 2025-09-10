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
    bool isValidBST(TreeNode* root) {
        return valid(root, LLONG_MIN, LLONG_MAX);
    }
    
    bool valid(TreeNode* root, long long min, long long max) {
        if (!root) return true;
        if (min >= root->val || max <= root->val) return false;
        return valid(root->left, min, root->val) && valid(root->right, root->val, max);
    }
};