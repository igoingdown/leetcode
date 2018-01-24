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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return NULL;
        return build(nums, 0, n - 1);
    }
    TreeNode* build(vector<int>& nums, int b, int e) {
        if (b > e || b < 0 || e >= nums.size()) return NULL;
        int mid = b + ((e - b) >> 1);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, b, mid - 1);
        root->right = build(nums, mid + 1, e);
        return root;
    }
};