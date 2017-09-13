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
    vector<TreeNode*> genTrees(int b, int e) {
        vector<TreeNode* > res;
        if (b > e) {
            res.push_back(NULL);
            return res;
        } else if (b == e) {
            res.push_back(new TreeNode(b));
            return res;
        } else {
            for (int i = b; i <= e; i++) {
                vector<TreeNode*> left = genTrees(b, i - 1);
                vector<TreeNode*> right = genTrees(i + 1, e);
                for (TreeNode* l: left) {
                    for (TreeNode* r : right) {
                        TreeNode* root = new TreeNode(i);
                        root->left = l;
                        root->right = r;
                        res.push_back(root);
                    }
                }
            }
            return res;
        }
        
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*> ();
        }
        return genTrees(1, n);
    }
};