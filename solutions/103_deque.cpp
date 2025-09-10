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
        deque<TreeNode*> q, next;
        q.push_back(root);
        int layer = 1;
        while (!q.empty()) {
            vector<int> v;
            while (!q.empty()) {
                TreeNode* cur = NULL;
                if (layer & 1) {
                    cur = q.back(); q.pop_back();
                    if (cur->left) next.push_front(cur->left);
                    if (cur->right) next.push_front(cur->right); 
                } else {
                    cur = q.front(); q.pop_front();
                    if (cur->right) next.push_back(cur->right); 
                    if (cur->left) next.push_back(cur->left);
                }
                v.push_back(cur->val);
            }
            swap(q, next);
            res.push_back(v);
            layer++;
        }
        return res;
    }
};