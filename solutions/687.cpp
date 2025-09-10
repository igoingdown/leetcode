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
    int maxLength = 0;
    int pathLen(TreeNode* root, int t) {
        int res = 0;
        if (!root) return res;
        if (root->val == t) {
            res++;
            res += max(pathLen(root->left, t), pathLen(root->right, t));
            return res;
        } else return res;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int left = 0, right = 0;
        if (root->left) left = pathLen(root->left, root->val);
        if (root->right) right = pathLen(root->right, root->val);
        maxLength = max(left + right, maxLength);
        longestUnivaluePath(root->left);
        longestUnivaluePath(root->right);
        return maxLength;
    }
};