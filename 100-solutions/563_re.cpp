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
    map<TreeNode*, int> m;
    int find_sum(TreeNode* root) {
        if (m.find(root) != m.end()) return m[root];
        return m[root] = find_sum(root->left) + find_sum(root->right) + root->val;
    }
    int findTilt(TreeNode* root) {
        if (!root) return 0;
        m[NULL] = 0;
        int leftSum = find_sum(root->left);
        int rightSum = find_sum(root->right);
        return abs(rightSum - leftSum) + findTilt(root->left) + findTilt(root->right);
    }
};