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
        vector<TreeNode *> res(1, NULL);
        for (int i = 1; i <= n; i++) {
            int len = res.size();
            for (int j = 0; j < len; j++) {
                auto head = res[j], cur = head;
                while (head) {
                    if (head->right) {
                        auto tmp = head->right; head->right = new TreeNode(i);
                        head->right->left = tmp;
                        res.push_back(copy(res[j]));
                        head->right = head->right->left; 
                    } else {
                        head->right = new TreeNode(i);
                        res.push_back(copy(res[j]));
                        head->right = NULL;
                    }
                    head = head->right;
                }
                TreeNode * tmp = new TreeNode(i);
                tmp->left = res[j]; res[j] = tmp;
            }
        }
        return res.size() == 1 && res[0] == NULL ? vector<TreeNode*>() : res;
    }
    TreeNode * copy(TreeNode *root) {
        if (!root) return NULL;
        TreeNode *new_root = new TreeNode(root->val);
        new_root->left = copy(root->left);
        new_root->right = copy(root->right);
        return new_root;
    }
};