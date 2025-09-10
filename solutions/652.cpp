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
    string serialize(TreeNode* root, map<string, vector< TreeNode* > >& m) {
        if (!root) return "";
        string s = "(" + serialize(root->left, m) + to_string(root->val) + serialize(root->right, m) + ")";
        m[s].push_back(root);
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string, vector<TreeNode*>> m;
        serialize(root, m);
        vector<TreeNode*> res(0);
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            if (iter->second.size() > 1) res.push_back(iter->second[0]); 
        }
        return res;
    }
};