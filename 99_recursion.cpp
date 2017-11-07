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
    TreeNode* first, * second, *pre;
    void find_nodes(TreeNode* root) {
        if (!root) return;
        find_nodes(root->left);
        if (!first && pre->val >= root->val) first = pre;
        if (first && pre->val >= root->val) second = root;
        pre = root;
        find_nodes(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        if (!root) return;
        first = NULL, second = NULL, pre = new TreeNode(INT_MIN);
        find_nodes(root);
        swap(first->val, second->val);
    }
};