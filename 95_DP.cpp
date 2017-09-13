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
    TreeNode* copy (TreeNode* root) {
        if (!root) {
            return NULL;
        }
        TreeNode* newRoot = new TreeNode(root->val);
        newRoot->left = copy(root->left);
        newRoot->right = copy(root->right);
        return newRoot;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) {
            return {};
        }
        vector<TreeNode*> result;
        vector<TreeNode*> preResult(1, NULL);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < preResult.size(); j++) {
                TreeNode* r = new TreeNode(i);
                TreeNode* nodeJ = preResult[j];
                r->left = copy(nodeJ);
                result.push_back(r);
                
                TreeNode* root = preResult[j];
                while (nodeJ) {
                    
                    TreeNode* nodeI = new TreeNode(i);
                    TreeNode* old_right = nodeJ->right;
                    nodeJ->right = nodeI;
                    nodeI->left = old_right;
                    result.push_back(copy(root));
                    nodeJ->right = old_right;
                    nodeJ = old_right;
                }  
                    
            }
            swap(result, preResult);
            result.clear();
        }
        return preResult;
    }
};