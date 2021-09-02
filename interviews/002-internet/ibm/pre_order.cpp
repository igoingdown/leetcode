#include <iostream>
#include <vector>
#include <stack>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};

void pre_order(TreeNode *root);

int main() {
	TreeNode* root = new TreeNode(0);
	root->left = new TreeNode(1);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	pre_order(root);
	return 0;
}

void pre_order(TreeNode *root) {
	if (!root) return;
	stack<TreeNode*> s;
	s.push(root);
	while (!s.empty()) {
		auto cur = s.top(); s.pop();
		cout << cur->val << endl;
		while (cur) {
			if (cur->left) cout << cur->left->val << endl;
			if (cur->right) s.push(cur->right);
			cur = cur->left;
		}
	}
}