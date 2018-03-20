#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


bool is_sub_struct(TreeNode *root, TreeNode *node);
bool is_head(TreeNode *root, TreeNode *node);

int main() {

	return 0;
}


bool is_head(TreeNode *root, TreeNode *node) {
	if (!node) return true;
	if (!root) return false;
	return root->val == node->val && is_head(root->left, node->left) && is_head(root->right, node->right);
}

bool is_sub_struct(TreeNode *root, TreeNode *node) {
	if (!node) return true;
	if (!root) return false;
	return is_head(root, node) || is_sub_struct(root->left, node) || is_sub_struct(root->right, node) 
}