/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q, next;
        q.push(root);
        while (!q.empty()) {
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                if (cur->left) next.push(cur->left);
                if (cur->right) next.push(cur->right);
                if (!q.empty()) cur->next = q.front();
            }
            swap(q, next);
        }
    }
};