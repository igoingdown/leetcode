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
    int findSecondMinimumValue(TreeNode* root) {
        int min_ele = root->val, sec_min = -1;
        if (!root->left) {
            return sec_min;
        } else {
            if (root->left->val != root->val && root->right->val != root->val) {
                return min(root->left->val, root->right->val);
            } else {
                int sec_min_left = root->left->val;
                int sec_min_right = root->right->val;
                if (root->left->val == root->val) {
                    sec_min_left = findSecondMinimumValue(root->left);
                }
                if (root->right->val == root->val) {
                    sec_min_right = findSecondMinimumValue(root->right);
                }
                if (sec_min_left == -1 && sec_min_right == -1) {
                    return -1;
                } else if (sec_min_left == -1) {
                    return sec_min_right;
                } else if (sec_min_right == -1) {
                    return sec_min_left;
                } else {
                    return min(sec_min_left, sec_min_right);
                }
            
            }
        }
    }
};