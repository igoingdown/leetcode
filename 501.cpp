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
private:
    int max = 0;
    vector<int> res;
    int findSame(TreeNode* root, int t) {
        int res = 0;
        if (!root) return 0;
        if (root->val == t) res++;
        if (root->val >= t) res += findSame(root->left, t);
        if (root->val <= t) res += findSame(root->right, t);
        return res;
    }
public:
    vector<int> findMode(TreeNode* root) {
        if (!root) return res;
        int c = findSame(root, root->val);
        if (c > max) {
            res.clear();
            max = c;
            res.push_back(root->val);
        } else if (c == max) res.push_back(root->val);
        findMode(root->left);
        findMode(root->right);
        return res;
    }
};