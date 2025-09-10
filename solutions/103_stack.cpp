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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        stack<TreeNode*> s, next;
        s.push(root);
        int level = 1;
        while (!s.empty()) {
            vector<int> v;
            while (!s.empty()) {
                auto cur = s.top();
                s.pop();
                v.push_back(cur->val);
                if (level & 1) {
                    if (cur->left) next.push(cur->left);
                    if (cur->right) next.push(cur->right);
                } else {
                    if (cur->right) next.push(cur->right);
                    if (cur->left) next.push(cur->left);
                }
            }
            level++;
            swap(s, next);
            res.push_back(v);
        }
        return res;
    }
};