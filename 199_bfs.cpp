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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> cur, next;
        if (root) {
            cur.push(root);
        }
        while(!cur.empty()) {
            while(!cur.empty()) {
                TreeNode* node = cur.front(); cur.pop();
                if (cur.empty()) {
                    // 将最右侧元素写入结果
                    res.push_back(node->val);
                }
                 if (node->left) {
                     next.push(node->left);
                 }
                 if (node->right) {
                     next.push(node->right);
                 }
            }
            swap(cur, next);
        }
        return res;
    }
};
