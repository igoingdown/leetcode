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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            auto node = s.top();
            s.pop();
            if (node) {
                res.push_back(node->val);
                s.push(node->right);
                s.push(node->left);
            }
        }
        return res;
    }
};