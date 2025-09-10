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
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        if (!root) return res;
        if (root->left) {
            auto tmp = root->left;
            while (tmp->right) tmp = tmp->right;
            res = min(res, root->val - tmp->val);
        }
        if (root->right) {
            auto tmp = root->right;
            while (tmp->left) tmp = tmp->left;
            res = min(res, tmp->val - root->val);
        }
        int left_res = getMinimumDifference(root->left);
        int right_res = getMinimumDifference(root->right);
        return min(res, min(left_res, right_res));
    }
};