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
    int res = 0;
    int find_sum(TreeNode* root) {
        if (!root) return 0;
        int left = find_sum(root->left);
        int right = find_sum(root->right);
        res += abs(left - right);
        return left + right + root->val;
    }
    int findTilt(TreeNode* root) {
        find_sum(root);
        return res;
    }
};