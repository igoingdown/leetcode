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
    int findAndDelete(TreeNode* node) {
        int res;
        if (!node->left->right) {
            res = node->left->val;
            node->left = node->left->left;
            return res;
        }
        auto p = node;
        node = node->left;
        while (node->right) {
            p = node;
            node = node->right;
        }
        res = node->val;
        p->right = node->left;
        return res;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val == key) {
            if (root->left && root->right) {
                int val = findAndDelete(root);
                root->val = val;
            } else if (!root->left && !root->right) return NULL;
            else {
                TreeNode* tmp;
                tmp = root->left ? root->left : root->right;
                root->val = tmp->val;
                root->left = tmp->left;
                root->right = tmp->right;
            }
        } else if (root->val < key) root->right = deleteNode(root->right, key);
        else root->left = deleteNode(root->left, key);
        return root;
    }
};