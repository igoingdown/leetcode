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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q, next;
        vector<double> res;
        q.push(root);
        double sum = 0, l = q.size();
        while (!q.empty()) {
            auto cur = q.front();
            sum += cur->val;
            if (cur->left) next.push(cur->left);
            if (cur->right) next.push(cur->right);
            q.pop();
            if (q.empty()) {
                res.push_back(sum / l);
                sum = 0;
                l = next.size();
                swap(q, next);
            }
        }
        return res;
    }
};