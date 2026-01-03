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
void in_order_none_recursive(TreeNode* root);
void in_order_recursive(TreeNode* root);

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(4);
	in_order_recursive(root);
	in_order_none_recursive(root);
	return 0;
}

void in_order_recursive(TreeNode* root) {
	if (!root) return;
	in_order_recursive(root->left);
	cout << root->val << endl;
	in_order_recursive(root->right);
}


void in_order_none_recursive(TreeNode* root) {
	stack<TreeNode*> s;
	while (root || !s.empty()) {
		while (root) {
			s.push(root);
			root = root->left;
		}
		root = s.top(); s.pop();
		cout << root->val << endl;
		root = root->right;
	}
}