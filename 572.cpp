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
    bool isSame(TreeNode* t, TreeNode* s) {
        if (!t && !s) return true;
        else if(s && t && s->val == t->val) return isSame(t->left, s->left) && isSame(t->right, s->right);
        return false;
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (isSame(s, t)) return true;
        if (s) return isSubtree(s->left, t) || isSubtree(s->right, t);
        return false;
    }
};