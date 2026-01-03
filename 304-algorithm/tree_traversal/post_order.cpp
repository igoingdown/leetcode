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

struct SNode
{
	TreeNode* n;
	bool visited;
	SNode(TreeNode *p): n(p), visited(false) {};
};

void post_order_none_recursive(TreeNode* root);
void post_order_recursive(TreeNode* root);

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(4);
	post_order_recursive(root);
	// post_order_none_recursive(root);
	return 0;
}

void post_order_recursive(TreeNode* root) {
	if (!root) return;
	post_order_recursive(root->left);
	post_order_recursive(root->right);
	cout << root->val << endl;
}


void post_order_none_recursive(TreeNode* root) {
	if (!root) return;
	stack<SNode*> s;
	while(root) {
		s.push(new SNode(root));
		root = root->left;
	}
	while (!s.empty()) {
		auto cur = s.top();
		if (!cur->n->right || cur->visited) {
			s.pop();
			cout << cur->n->val << endl;
		} else {
			cur->visited = true;
			auto tmp = cur->n->right;
			while (tmp) {
				s.push(new SNode(tmp));
				tmp = tmp->left;
			}
		}
	}
}













