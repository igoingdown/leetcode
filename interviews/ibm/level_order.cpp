#include <iostream>
#include <queue>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};


void level_order(TreeNode *root);

int main() {
	TreeNode *root = new TreeNode(0);
	root->left = new TreeNode(1);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	level_order(root);
	return 0;
}

void level_order(TreeNode *root) {
	if (!root) return;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		cout << cur->val << endl;
		if (cur->left) q.push(cur->left);
		if (cur->right) q.push(cur->right);
	}
}