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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0) {
            return NULL;
        }
        if (inorder.size() == 1) {
            return new TreeNode(inorder[0]);
        }
        map<int, int> value2index;
        for (int i = 0; i < inorder.size(); i++) {
            value2index[inorder[i]] = i;
        }
        TreeNode * root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, value2index);
        return root;
    }
    
    TreeNode * buildTree(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end,  map<int, int>& value2index) {
        if (pre_start > pre_end || in_start > in_end) {
            return NULL;
        }
        TreeNode * root = new TreeNode(preorder[pre_start]);
        int root_index = value2index[root->val];
        root->left = buildTree(preorder, pre_start + 1, pre_start + root_index - in_start, inorder, in_start, root_index - 1, value2index);
        root->right = buildTree(preorder, pre_start + root_index - in_start + 1, pre_end, inorder, root_index + 1, in_end, value2index);
        return root;
    }
};
