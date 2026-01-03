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
        long long last_visited = LLONG_MIN;
        return valid(root, last_visited);
    }
    
    bool valid(TreeNode* root, long long &last_visited) {
        if (!root) return true;
        if (!valid(root->left, last_visited)) return false;
        if (last_visited >= root->val) return false;
        last_visited = root->val;
        return valid(root->right, last_visited);
    }
};