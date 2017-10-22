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
    private: unordered_map<TreeNode*, int> m;
    int get_depth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (m.find(root) != m.end()) {
            return m[root];
        }
        return m[root] = max(get_depth(root->left), get_depth(root->right)) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return isBalanced(root->left) && isBalanced(root->right) && abs(get_depth(root->left) - get_depth(root->right)) < 2;
    }
};