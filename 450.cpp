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
        TreeNode* p = node->left;
        node = node->left->right;
        while (node->right) {
            p = node;
            node = node->right;
        }
        p->right = node->left;
        return node->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val == key) {
            if (root->right && root->left) {
                int val = findAndDelete(root);
                root->val = val;
            }
            else if (!root->right && !root->left) return NULL;
            else {
                TreeNode* tmp;
                if (root->right) tmp = root->right;
                else tmp = root->left;
                root->val = tmp->val;
                root->left = tmp->left;
                root->right = tmp->right;
            } 
        } else if (root->val < key) root->right = deleteNode(root->right, key);
        else root->left = deleteNode(root->left, key);
        return root;
    }
};