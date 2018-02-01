#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

void in_order(TreeNode* root);


int main() {
	TreeNode* root = new TreeNode(0);
	root->left = new TreeNode(1);
	root->right = new TreeNode(2);
	root->left->right = new TreeNode(3);
	in_order(root);
	return 0;
}

void in_order(TreeNode* root) {
	if (!root) return;
	stack<TreeNode*> s;
	while (root) {
		s.push(root);
		root = root->left;
	}
	while (!s.empty()) {
		auto cur = s.top(); s.pop();
		cout << cur->val << endl;
		cur = cur->right;
		while (cur) {
			s.push(cur);
			cur = cur->left;
		}
	}
}