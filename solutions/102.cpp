/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> cur, next;
        if (root) {
            cur.push(root);
        }
        while (!cur.empty()) {
            vector<int> layer;
            while (!cur.empty()) {
                TreeNode *node = cur.front();
                cur.pop();
                if (node) {
                    layer.push_back(node->val);
                    if (node->left) {
                        next.push(node->left);
                    }
                    if (node->right) {
                        next.push(node->right);
                    }
                }
            }
            res.push_back(layer);
            swap(cur, next);
        }
        return res;
    }
};
