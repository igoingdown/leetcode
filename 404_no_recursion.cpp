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
    int sumOfLeftLeaves(TreeNode* root) {
        if (! root) {
            return 0;
        } else {
            stack<TreeNode*> s;
            s.push(root);
            int res = 0;
            while (! s.empty()) {
                TreeNode* node = s.top();
                s.pop();
                if (node -> left) {
                    if (! node -> left -> left && ! node -> left ->right) {
                        res += node -> left -> val;
                    } else {
                        s.push(node -> left);
                    }
                }
                if (node -> right) {
                    s.push(node -> right);
                }
            }
            return res;
        }
    }
};
