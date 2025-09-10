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
        TreeLinkNode *levelStart = root, *cur, *pre;
        while (1) {
            cur = levelStart, pre = NULL;
            while (cur) {
                if (cur->left) {
                    if (pre) pre->next = cur->left;
                    else levelStart = cur->left;
                    pre = cur->left;
                }
                if (cur->right) {
                    if (pre) pre->next = cur->right;
                    else levelStart = cur->right;
                    pre = cur->right;
                }
                cur = cur->next;
            }
            if (!pre) break;
        }
    }
};