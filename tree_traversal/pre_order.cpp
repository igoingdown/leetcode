#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {};
};
void pre_order_none_recursive(TreeNode* root);
void pre_order_recursive(TreeNode* root);

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(4);
	// TreeNode * tmp = root;
	pre_order_recursive(root);
	pre_order_none_recursive(root);
	return 0;
}

void pre_order_recursive(TreeNode* root) {
	if (!root) return;
	cout << root->val << endl;
	pre_order_recursive(root->left);
	pre_order_recursive(root->right);
}


void pre_order_none_recursive(TreeNode* root) {
	if (!root) return;
	stack<TreeNode* > s;
	s.push(root);
	while (!s.empty()) {
		auto cur = s.top();
		s.pop();
		cout << cur->val << endl;
		while (cur) {
			if (cur->left) cout << cur->left->val << endl;
			if (cur->right) s.push(cur->right);
			cur = cur->left;
		}
	}
}