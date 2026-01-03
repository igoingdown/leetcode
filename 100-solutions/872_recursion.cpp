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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1, res2;
        inOrder(root1, res1);
        inOrder(root2, res2);
        int n1 = res1.size(), n2 = res2.size();
        if (n1 != n2) return false;
        for (int i = 0; i < n1; i++) {
            if (res1[i] != res2[i]) return false;
        }
        return true;
    }
    
    void inOrder(TreeNode *root, vector<int> &res) {
        if (!root) return;
        inOrder(root->left, res);
        if (!root->left && !root->right) res.push_back(root->val);
        inOrder(root->right, res);
    }
};