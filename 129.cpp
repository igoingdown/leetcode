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
    void dfs(int& sum, vector<TreeNode*>& p, TreeNode* root) {
        if (root->left) {
            p.push_back(root->left);
            dfs(sum, p, root->left);
            p.pop_back();
        }
        if (root->right) {
            p.push_back(root->right);
            dfs(sum, p, root->right);
            p.pop_back();
        }
        if (!root->left && !root->right) {
            int tmp = 0;
            for (int i = 0; i < p.size(); i++) {
                tmp = tmp * 10 + p[i]->val;
            }
            sum += tmp;
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if (!root) return sum;
        vector<TreeNode*> path(1, root);
        dfs(sum, path, root);
        return sum;
    }
};