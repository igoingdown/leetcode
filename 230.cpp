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
    int kthSmallest(TreeNode* root, int k) {
        int low = root->val, high = root->val;
        TreeNode* l = root, *r = root;
        while (l) {
            low = l->val;
            l = l->left;
        }
        while (r) {
            high = r->val;
            r = r->right;
        }
        int  mid = root->val;
        while (low < high) {
            mid = low + ((high - low) >> 1);
            if (countLE(root, mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    
    
    int countLE(TreeNode* root, int mid) {
        if (!root) {
            return 0;
        } else {
            int num = 0;
            if (mid < root->val) {
                num += countLE(root->left, mid);
            } else {
                num += countLE(root->left, mid) + 1 + countLE(root->right, mid);
            }
            return num;
        }
    }
};