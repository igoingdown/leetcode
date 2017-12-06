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
        vector<int> res(0);
        if (!root) return res;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            auto cur = s.top();
            s.pop();
            if (cur) {
                res.push_back(cur->val);
                s.push(cur->right);
                s.push(cur->left);
            }
        }
        return res;
    }
};