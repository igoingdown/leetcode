#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};

TreeNode * getKthNode(TreeNode *root, int k);
void helper(TreeNode *root, int &k, TreeNode *&res);

int main() {
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);
	int k;
	while (cin >> k) {
		TreeNode *res = getKthNode(root, k);
		if (res) cout << res->val << endl;
		else cout << "NULL" << endl;
	}
	return 0;
}

TreeNode *getKthNode(TreeNode *root, int k) {
	TreeNode *res = NULL;
	helper(root, k, res);
	return res;
}

void helper(TreeNode *root, int &k, TreeNode *&res) {
	if (!root || res) return;
	helper(root->left, k, res);
	k--;
	if (k == 0) {
		res = root;
		return;
	}
	helper(root->right, k, res);
}

