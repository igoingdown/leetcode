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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> cur, next;
        if (root) {
            cur.push(root);
        }
        while(!cur.empty()) {
            int layer_max = numeric_limits<int>::min();
            while (!cur.empty()) {
                TreeNode *node = cur.front(); cur.pop();
                if (node) {
                    layer_max = max(layer_max, node->val);
                    if (node->left) {
                        next.push(node->left);
                    }
                    if (node->right) {
                        next.push(node->right);
                    }
                }
            }
            res.push_back(layer_max);
            swap(cur, next);
        }
        return res;

    }
};
