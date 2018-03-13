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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*> ();
        return dfs(1, n);
    }
    vector<TreeNode*> dfs(int b, int e) {
        if (b > e) return vector<TreeNode*> (1, NULL);
        vector<TreeNode*> res;
        for (int i = b; i <= e; i++) {
            auto left = dfs(b, i - 1), right = dfs(i + 1, e);
            for (auto l_node : left) {
                for (auto r_node : right) {
                    TreeNode *root = new TreeNode(i);
                    root->left = l_node; root->right = r_node;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};