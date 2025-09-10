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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* t = new TreeNode(v);
            t->left = root;
            return t;
        }
        queue<TreeNode*> q, next;
        q.push(root);
        int l = 1;
        while (!q.empty() && l < d - 1) {
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                if (cur->left) next.push(cur->left);
                if (cur->right) next.push(cur->right);
            }
            swap(q, next);
            l++;
        }
        while (!q.empty()) {
            TreeNode* p = q.front();
            q.pop();
            TreeNode* new_left = new TreeNode(v);
            new_left->left = p->left;
            p->left = new_left;
            TreeNode* new_right = new TreeNode(v);
            new_right->right = p->right;
            p->right = new_right;
        }
        return root;
    }
};
