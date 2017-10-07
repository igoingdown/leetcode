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
    int get_level(TreeNode* r) {
        if (!r) {
            return 0;
        }
        return 1 + max(get_level(r->left), get_level(r->right));
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        int l = get_level(root->left), r = get_level(root->right);
        if (l >= r && l > 0) {
            return findBottomLeftValue(root->left);
        } else if (l < r && r > 0) {
            return findBottomLeftValue(root->right);
        } else {
            return root->val;
        }
    }
};