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
    TreeNode* dfs(vector<int>& nums, int l, int r) {
        if (l >= r) return NULL;
        int max_index = l;
        for (int i = l; i < r; i++) max_index = nums[max_index] < nums[i] ? i : max_index;
        TreeNode* root = new TreeNode(nums[max_index]);
        root->left = dfs(nums, l, max_index);
        root->right = dfs(nums, max_index + 1, r);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums, 0, nums.size());
    }
};