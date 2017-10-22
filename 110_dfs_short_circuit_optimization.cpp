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
        if (!root) return 0;
        int left_depth = get_depth(root->left);
        int right_depth = get_depth(root->right);
        if (left_depth == -1 || right_depth == -1 || abs(left_depth - right_depth) > 1) {
            return -1;
        }
        return max(left_depth, right_depth) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return get_depth(root) != -1;
    }
};