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
        queue<pair<TreeNode*, int>> q, next;
        q.push(make_pair(root, 1));
        res = 1;
        while (!q.empty()) {
            int l = q.front().second, r = l;
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                r = cur.second;
                if (cur.first->left) next.push(make_pair(cur.first->left, cur.second * 2));
                if (cur.first->right) next.push(make_pair(cur.first->right, cur.second * 2 + 1));
            }
            swap(q, next);
            res = max(res, r - l + 1);
        }
        return res;
    }
};