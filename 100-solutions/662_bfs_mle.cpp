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
    int widthOfBinaryTree(TreeNode* root) {
        int res = 0;
        if (!root) return res;
        queue<TreeNode*> q, next;
        q.push(root);
        vector<TreeNode*> level;
        while (!q.empty()) {
            level.clear();
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                level.push_back(cur);
                if (cur) {
                    next.push(cur->left);
                    next.push(cur->right);
                } else {
                    next.push(NULL);
                    next.push(NULL);
                }
            }
            swap(q, next);
            int b = -1, e = level.size();
            for (int i = 0; i < level.size(); i++) {
                if (level[i]) {
                    b = i;
                    break;
                }
            }
            if (b == -1) return res;
            for (int i = level.size() - 1; i >= 0; i--) {
                if (level[i]) {
                    e = i;
                    break;
                }
            }
            res = max(res, e - b + 1);
        }
        return res;
    }
};