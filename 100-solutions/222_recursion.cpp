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
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        TreeNode* l = root;
        TreeNode* r = root;
        int hl = 0, hr = 0;
        while (l) {
            l = l->left;
            hl++;
        }
        while (r) {
            r = r->right;
            hr++;
        }
        if (hl == hr) {
            return (int)pow(2, hr) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};