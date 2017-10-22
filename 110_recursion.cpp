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
    int get_depth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return max(get_depth(root->left), get_depth(root->right)) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        if (!isBalanced(root->left) || !(isBalanced(root->right))) return false;
        return abs(get_depth(root->left) - get_depth(root->right)) < 2;
    }
};