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
    TreeNode* dfs(const vector<int>& nums, int b, int e) {
        if (b > e) {
            return NULL;
        } else if (b == e) {
            return new TreeNode(nums[b]);
        } else {
            int mid = b + ((e - b) >> 1);
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = dfs(nums, b, mid - 1);
            root->right = dfs(nums, mid + 1, e);
            return root;
        }
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n < 1) {
            return NULL;
        } else if (n == 1) {
            return new TreeNode(nums[0]);
        }
        return dfs(nums, 0, n - 1);
    }
};