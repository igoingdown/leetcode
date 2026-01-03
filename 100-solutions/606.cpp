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
    string tree2str(TreeNode* t) {
        string s, l;
        if (!t) return s;
        s += to_string(t->val);
        if (t->left) s += "(" + tree2str(t->left) + ")";
        if (t->right) s += (t->left ? "(" + tree2str(t->right) + ")" : "()(" + tree2str(t->right) + ")");
        return s;
    }
};