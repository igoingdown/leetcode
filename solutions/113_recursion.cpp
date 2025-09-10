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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> path;
        dfs(res, path, root, sum);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& path, TreeNode* root, int sum) {
        path.push_back(root->val);
        if (root->val == sum && !root->left && !root->right) res.push_back(path);
        if (root->left) dfs(res, path, root->left, sum - root->val);
        if (root->right) dfs(res, path, root->right, sum - root->val);
        path.pop_back();
    }
};