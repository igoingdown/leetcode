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
    int maxDepth(TreeNode* root) {
        if (! root) {
            return 0;
        } else {
            int res = 0;
            queue<TreeNode*> q;
            q.push(root);
            int s = q.size();
            while (! q.empty()) {
                TreeNode* f = q.front();
                if (f->left) {
                    q.push(f->left);
                }
                if (f->right) {
                    q.push(f->right);
                }
                q.pop();
                s--;
                if (s == 0) {
                    res++;
                    s = q.size();
                }
            }
            return res;
        }
        
    }
};