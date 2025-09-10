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
    bool findPath(TreeNode* root, TreeNode* node, vector<TreeNode*>& path) {
        if (!root) return false;
        if (root == node) {
            return true;
        } else {
            path.push_back(root->left);
            if (findPath(root->left, node, path)) return true;
            path.pop_back();
            path.push_back(root->right);
            if (findPath(root->right, node, path)) return true;
            path.pop_back();
        }
        return false;
    } 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1(1, root), path2(1, root);
        bool p_found = findPath(root, p, path1);
        bool q_found = findPath(root, q, path2);
        int l = min(path1.size(), path2.size());
        TreeNode* res = NULL;
        for (int i = 0; i < l; i++) {
            if (path1[i] == path2[i]) res = path1[i];
            else break;
        }
        return res;
    }
};