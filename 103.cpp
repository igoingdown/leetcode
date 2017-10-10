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
        vector< vector<int> > res(0, vector<int> (0, 0));
        if (!root) {
            return res;
        }
        int level = 0;
        stack<TreeNode*> s;
        s.push(root);
        vector<int> tmp;
        stack<TreeNode*> next;
        while (!s.empty()) {
            while (!s.empty()) {
                auto node = s.top();
                tmp.push_back(node->val);
                s.pop();
                if (level % 2 == 0) {
                    if (node->left) {
                        next.push(node->left);
                    }
                    if (node->right) {
                        next.push(node->right);
                    }
                } else {
                    if (node->right) {
                        next.push(node->right);
                    }
                    if (node->left) {
                        next.push(node->left);
                    }
                }
            }
            res.push_back(tmp);
            tmp.clear();
            swap(s, next);
            level++;
        }
        return res;
    }
};