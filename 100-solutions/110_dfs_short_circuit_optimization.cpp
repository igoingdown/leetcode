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
    unordered_map<TreeNode*, int> m = {{NULL, 0}};
    int get_depth(TreeNode *root) {
        if (!root) return 0;
        int left = get_depth(root->left), right = get_depth(root->right);
        return left >= 0 && right >= 0 && abs(left - right) < 2 ? max(left, right) + 1 : -1;
    }
    bool isBalanced(TreeNode* root) {
        return get_depth(root) >= 0;
    }
};