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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        int local_max = INT_MIN, last_level = 1;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            last_level--;
            local_max = max(local_max, cur->val);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
            if (last_level == 0) {
                res.push_back(local_max);
                local_max = INT_MIN;
                last_level = q.size();
            }
        }
        return res;
    }
};