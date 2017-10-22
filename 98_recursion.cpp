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
    bool isValidBST(TreeNode* root, TreeNode* min_node, TreeNode* max_node) {
        if (!root) {
            return true;
        }
        if ((min_node && root->val <= min_node->val) || (max_node && root->val >= max_node->val)) {
            return false;
        }
        return isValidBST(root->left, min_node, root) && isValidBST(root->right, root, max_node);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }
};