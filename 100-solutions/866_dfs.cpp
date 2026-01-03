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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<vector<TreeNode*>> paths;
        vector<TreeNode*> path(1, root);
        int maxDepth = 1;
        dfs(paths, path, maxDepth, root);
        if (paths.size() == 1) return paths[0].back();
        else {
            TreeNode* res = root;
            for (int i = 0; i < paths[0].size(); i++) {
                bool isSame = true;
                for (int j = 1; j < paths.size(); j++) {
                    if (paths[j][i] != paths[j - 1][i]) isSame = false;
                }
                if (isSame) res = paths[0][i];
                else break;
            }
            return res;
        }
    }
    
    void dfs(vector<vector<TreeNode*>> &paths, vector<TreeNode*> &path, int &maxDepth, TreeNode* root) {
        if (!root->left && !root->right) {
            if (path.size() > maxDepth) {
                paths.clear();
                paths.push_back(path);
                maxDepth = path.size();
            } else if (path.size() == maxDepth) paths.push_back(path);
        }
        if (root->left) {
            path.push_back(root->left);
            dfs(paths, path, maxDepth, root->left);
            path.pop_back();
        }
        if (root->right) {
            path.push_back(root->right);
            dfs(paths, path, maxDepth, root->right);
            path.pop_back();
        }
    }
};