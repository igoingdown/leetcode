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
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string> > res(0, vector<string>(0));
        if (!root) return res;
        auto left = printTree(root->left);
        auto right = printTree(root->right);
        int row_l = left.size(), row_r = right.size(), column_l = 0, column_r = 0;
        if (row_l) column_l = left[0].size();
        if (row_r) column_r = right[0].size();
        int r = max(row_l, row_r), c = max(column_l, column_r);
        vector<string> first_row(2 * c + 1, "");
        first_row[c] = to_string(root->val);
        for (int i = 0; i < r; i++) {
            // 左边为空
            if (row_l <= i) left.push_back(vector<string>(1, ""));
            // 左侧为空
            if (row_r <= i) right.push_back(vector<string>(1, ""));
            // 左侧宽度不够
            while (left[i].size() != c) {
                vector<string> tmp(2 * left[i].size() + 1, "");
                for (int j = 0; j < left[i].size(); j++) tmp[2 * j + 1] = left[i][j];
                left[i] = tmp;
            }
            // 右侧宽度不够
            while(right[i].size() != c) {
                vector<string> tmp(2 * right[i].size() + 1, "");
                for (int j = 0; j < right[i].size(); j++) tmp[2 * j + 1] = right[i][j];
                right[i] = tmp;
            }
            left[i].push_back("");
            left[i].insert(left[i].end(), right[i].begin(), right[i].end());
        }
        left.insert(left.begin(), first_row);
        return left;
    }
};