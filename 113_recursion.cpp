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
    void dfs(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& path) {
        if (root->val == sum && !root->left && !root->right) {
            path.push_back(root->val);
            res.push_back(vector<int> (path.begin(), path.end()));
            path.pop_back();
        }
        path.push_back(root->val);
        if (root->left) dfs(root->left, sum - root->val, res, path);
        if (root->right) dfs(root->right, sum - root->val, res, path);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector< vector<int> > res;
        if (!root) return res;
        vector<int> path;
        dfs(root, sum, res, path);
        return res;
    }
};