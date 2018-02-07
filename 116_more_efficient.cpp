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
        TreeLinkNode *levelStart = root, *cur;
        while (levelStart) {
            cur = levelStart;
            while (cur) {
                if (cur->left) cur->left->next = cur->right;
                if (cur->right && cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            levelStart = levelStart->left;
        }
    }
};