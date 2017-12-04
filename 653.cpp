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
    TreeNode* find_v(TreeNode* root, int k) {
        if (!root) return root;
        if (k > root->val) return find_v(root->right, k);
        else if (k < root->val) return find_v(root->left, k);
        else return root;
    }
    bool re(TreeNode* cur, TreeNode* t, int k) {
        if (!cur) return false;
        auto p = find_v(t, k - cur->val);
        if (p && p!= cur) return true;
        else return re(cur->left, t, k) || re(cur->right, t, k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        return re(root, root, k);
    }
};